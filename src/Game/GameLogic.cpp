#include "GameLogic.h"

SW::GameLogic::GameLogic()
    : _tick(TICK_DEFAULT),
      _tick_last(0),
      _cursor_position({0, 0}),
      _stats() {
    // Load building types
    this->loadBuildingConfigs({
        {SDLK_1, "city_hall"},
        {SDLK_2, "farm"},
        {SDLK_3, "house"},
        {SDLK_4, "lumber_mill"},
        {SDLK_5, "mine"}
    });
    if (!this->_building_configs.empty()) {
        this->_selected_config = (*this->_building_configs.cbegin()).first;
    }
}

SW::GameLogic::~GameLogic() {
    this->_buildings.clear();
    for (auto const & config : this->_building_configs) {
        delete config.second;
    }
    this->_building_configs.clear();
}

void SW::GameLogic::loadBuildingConfigs(std::initializer_list<BuildingConfigKeyboardBinding> bindings) {
    for (auto const & binding : bindings) {
        auto * config = new BuildingConfig(binding.config_name);
        this->_building_configs.insert(std::pair<std::string, BuildingConfig *>(binding.config_name, config));
        this->_building_configs_bindings.insert(std::pair<uint16_t , std::string>(binding.key_code, binding.config_name));
    }
}

void SW::GameLogic::process(const Renderer & renderer) {
    if (this->tick()) {
        this->_stats.updateResourcesFromBuildings(this->_buildings);
        _Info(this->_stats.toString());
        if (!this->_stats.tick()) {
            // You are dead man
        }
    }
    // Render the world
    for (const auto & building : this->_buildings) {
        renderer.render(building.second.get());
    }
}

bool SW::GameLogic::build(const std::string & config_name, SDL_Point position) {
    BuildingConfig * config = this->_building_configs[config_name];
    if (config == nullptr) {
        _Error("Building type '" + config_name + "' does not exist.");
        return false;
    }
    // Normalize building coordinates
    SDL_Point game_coordinates = GameLogic::convertToGameCoordinates(position);

    // Check other building collisions
    // TODO: Do it!

    // Add building to render queue
    this->_buildings.add(std::make_shared<Building>(Building(config, game_coordinates)));

    _Info("Building type '" + config_name + "' built on coordinates " + std::to_string(game_coordinates.x) + "x" + std::to_string(game_coordinates.y) + ".");
    return true;
}

bool SW::GameLogic::destroy(SDL_Point position) {
    position = GameLogic::convertFromGameCoordinates(position);

    for (const auto & building : this->_buildings) {
        // TODO: Do detection stuff and destroy colliding building
        if (false) {
            this->_buildings.remove(building.first);
            return true;
        }
    }

    return false;
}

SDL_Point SW::GameLogic::convertToGameCoordinates(SDL_Point point) {
    double spacing = GameLogic::TILE_SIZE + GameLogic::TILE_SPACING;
    return {
            (int)floor(point.x / spacing),
            (int)floor(point.y / spacing)
    };
}

SDL_Point SW::GameLogic::convertFromGameCoordinates(SDL_Point point) {
    return {
            GameLogic::TILE_SPACING + (GameLogic::TILE_SIZE + GameLogic::TILE_SPACING) * point.x,
            GameLogic::TILE_SPACING + (GameLogic::TILE_SIZE + GameLogic::TILE_SPACING) * point.y
    };
}

bool SW::GameLogic::tick() {
    uint32_t tick_current = SDL_GetTicks();
    if (tick_current - this->_tick_last >= this->_tick) {
        this->_tick_last = tick_current;
        return true;
    }
    return false;
}

void SW::GameLogic::handleEvent(const SDL_Event & event) {
    switch (event.type) {
            // Keyboard handler
        case SDL_KEYDOWN:
            this->handleKeyboard(event.key.keysym.sym);
            break;
        case SDL_MOUSEBUTTONUP:
            // Mouse click handler
            this->handleMouseClick(event.button);
            break;
        default:
            break;
    }
}

void SW::GameLogic::handleKeyboard(SDL_Keycode code) {
    auto iterator = this->_building_configs_bindings.find(code);
    if (iterator != end(this->_building_configs_bindings)) {
        this->_selected_config = iterator->second;
        _Info("Selected building '" + iterator->second + "'.");
    }
}

void SW::GameLogic::handleMouseClick(const SDL_MouseButtonEvent & click) {
    switch (click.button) {
        case SDL_BUTTON_LEFT:
            // Build new building
            assert(this->build(this->_selected_config, {click.x, click.y}));
            break;
        case SDL_BUTTON_RIGHT:
            // Destroy existing building
            this->destroy({click.x, click.y});
            break;
        default:
            break;
    }
}
