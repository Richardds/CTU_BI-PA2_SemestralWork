#include "GameLogic.h"
#include "../System/BinaryReader.h"
#include "../System/BinaryWriter.h"

SW::GameLogic::GameLogic(const Window & window)
    : _window(window),
      _running(true),
      _tick(TICK_DEFAULT),
      _tick_last(0),
      _game_time(0),
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
    this->clearGameState();
    this->_building_configs.clear();
}

void SW::GameLogic::clearGameState() {
    this->_tick_last = 0;
    this->_game_time = 0;
    this->_buildings.clear();
    this->_stats.reset();
}

void SW::GameLogic::loadBuildingConfigs(std::initializer_list<BuildingConfigKeyboardBinding> bindings) {
    for (auto const & binding : bindings) {
        BuildingConfig config(binding.config_name);
        this->_building_configs.insert(std::pair<std::string,
                std::shared_ptr<BuildingConfig>>(binding.config_name, std::make_shared<BuildingConfig>(config)));
        this->_building_configs_bindings.insert(std::pair<uint16_t , std::string>(binding.key_code, binding.config_name));
    }
}

void SW::GameLogic::process(const Renderer & renderer) {
    if (this->_running && this->tick()) {
        this->_game_time += GameLogic::TICK_DEFAULT / 1000;
        // Update buildings status
        for (auto const & building : this->_buildings) {
            building.second->tick();
        }
        // Update resources from buildings
        this->_stats.updateResourcesFromBuildings(this->_buildings);
        // Print game status
        _Info("Game time: " + std::to_string(this->_game_time));
        _Info(this->_stats.toString());
        // Update resources
        if (!this->_stats.tick()) {
            // Village does not have enough grain
            this->stop();
            _Info("");
            _Info(this->_stats.toString(true));
            _Info("");
            _Info("Game over! Your village does not have enough grain.");
            _Info("");
        }
    }
    // Render the world
    for (const auto & building : this->_buildings) {
        renderer.render(building.second.get());
    }
}

bool SW::GameLogic::build(const Building & to_build, uint32_t * building_id) {
    // Check if new building collides with others
    for (const auto & building : this->_buildings) {
        if (building.second->overlapsOtherRectangle(to_build)) {
            _Info("Cannot build '" + to_build.getConfig()->getTitle() + "' colliding with building '"
            + building.second->getConfig()->getTitle() + "' ID(" + std::to_string(building.first) + ").");
            return false;
        }
    }

    // Check if building collides with windows borders
    if (to_build.overlapsHorizontalLine(this->_window.getHeight()) || to_build.overlapsVerticalLine(this->_window.getWidth())) {
        _Info("Cannot build '" + to_build.getConfig()->getTitle() + "' colliding window borders.");
        return false;
    }

    // Add building to render queue
    uint32_t id = this->_buildings.add(std::make_shared<Building>(to_build));

    if (building_id != nullptr) {
        *building_id = id;
    }

    _Info("Building '" + to_build.getConfig()->getTitle() + "' built on coordinates ["
    + std::to_string(to_build.getGamePositionX()) + "," + std::to_string(to_build.getGamePositionY()) + "].");
    return true;
}

bool SW::GameLogic::clickBuild(const std::string & config_name, SW::Position position, uint32_t * building_id) {
    Building to_build(this->queryConfig(config_name), GameLogic::convertToGameCoordinates(position));

    // Check construction costs
    WorldStats::Stats costs = to_build.getConfig()->getBuildCostBase();
    if (!this->_stats.validateSufficientResources(costs)) {
        _Info("Cannot build '" + to_build.getConfig()->getTitle() + "' due to insufficient resources.");
        _Info("'" + to_build.getConfig()->getTitle() + "' costs: " + costs.toString());
        return false;
    }

    // Subtract construction costs
    if (this->build(to_build, building_id)) {
        this->_stats.increaseResources(costs, true);
        return true;
    }

    return false;
}

bool SW::GameLogic::forceBuild(const std::string & config_name, SW::Position position, uint32_t * building_id) {
    // Build new building
    std::shared_ptr<BuildingConfig> config = this->_building_configs[config_name];
    if (config == nullptr) {
        _Error("Cannot build with nonexistent config '" + this->_selected_config + "'.");
        return false;
    }
    Building to_build(config, position);

    return this->build(to_build, building_id);
}

bool SW::GameLogic::upgrade(SW::Position position) {
    uint32_t building_id = this->buildingClicked(position);
    if (building_id == 0) {
        return false;
    }
    std::shared_ptr<Building> building = this->_buildings.get(building_id);
    if (!building->isBuilt()) {
        _Info("Cannot upgrade building '" + building->getConfig()->getTitle() + "'. Building is under construction.");
        return false;
    }
    WorldStats::Stats costs = building->getConfig()->getBuildCostBase() * (building->getLevel() + 1);
    if (!this->_stats.validateSufficientResources(costs)) {
        _Info("Cannot upgrade building '" + building->getConfig()->getTitle() + "' due to insufficient resources.");
        return false;
    }
    if (building->levelUp()) {
        this->_stats.increaseResources(costs, true);
        _Info("Building '" + building->getConfig()->getTitle() + "' upgraded to level "
              + std::to_string(building->getLevel()) + ".");
        return true;
    }
    _Info("Cannot upgrade building '" + building->getConfig()->getTitle() + "'. Building is upgraded to maximum level.");
    return false;
}

bool SW::GameLogic::destroy(SW::Position position) {
    uint32_t building_id = this->buildingClicked(position);
    if (building_id == 0) {
        return false;
    }
    std::shared_ptr<Building> building = this->_buildings.get(building_id);
    // Process refund
    WorldStats::Stats refund = building->getConfig()->getBuildCostBase() * GameLogic::REFUND_MODIFIER;
    refund.grain = building->getConfig()->getBuildCostBase().grain * -3;
    // Validate sufficient resources
    if (!this->_stats.validateSufficientResources(refund * -1)) {
        _Info("Cannot destroy building '" + building->getConfig()->getTitle() + "' due to insufficient resources.");
        return false;
    }
    this->_stats.increaseResources(refund);
    this->_buildings.remove(building_id);
    return true;
}

bool SW::GameLogic::save(const std::string & path) {
    BinaryWriter writer;
    if (!writer.open(path)) {
        _Error("Failed to open game state file '" + path + "' for writing.");
        return false;
    }
    // Write save state metadata
    writer.write(Magic::GAME_STATE);
    uint8_t version = GameLogic::SUPPORTED_GAME_STATE_VERSION;
    writer.write(version);
    // Save game time
    writer.write(this->_game_time);
    // Write buildings
    writer.writeDirect((uint16_t)this->_buildings.size());
    for (const auto & building : this->_buildings) {
        // Write building ID
        // NOTE: This value is reserved for future use
        writer.write(building.first);
        // Write building state
        writer.writeObject(building.second.get());
    }
    // Write resources
    writer.writeObject(this->_stats);
    writer.close();
    _Info("Game state save to file '" + path + "' successfully.");
    return true;
}

bool SW::GameLogic::load(const std::string & path) {
    BinaryReader reader;
    if (!reader.open(path)) {
        _Error("Failed to open game state file '" + path + "' for reading.");
        return false;
    }
    // Validate save state metadata
    uint32_t magic;
    reader.read(magic);
    if (magic != Magic::GAME_STATE) {
        _Error("Magic mismatch in game state file '" + path + "'.");
        return false;
    }
    uint8_t version;
    reader.read(version);
    if (version != GameLogic::SUPPORTED_GAME_STATE_VERSION) {
        _Error("Unsupported game state file '" + path + "'.");
        return false;
    }
    // Clear game state
    this->clearGameState();
    // Read game time
    reader.read(this->_game_time);
    // Read buildings
    uint16_t building_count;
    uint32_t building_id;
    std::string building_config;
    Position building_position = {0, 0};
    uint8_t building_level;
    uint16_t building_construction_time_left;
    reader.read(building_count);
    while (building_count--) {
        // Read building ID
        // NOTE: We are not using building ID
        reader.read(building_id);
        reader.readString(building_config);
        reader.read(building_position);
        reader.read(building_level);
        reader.read(building_construction_time_left);
        if (!this->forceBuild(building_config, building_position, &building_id)) {
            _Error("Unable to place building '" + building_config + "' from saved game state.");
            return false;
        }
        // Set building post-construction attributes
        std::shared_ptr<Building> building = this->_buildings.get(building_id);
        building->setLevel(building_level);
        building->setBuiltInTicks(building_construction_time_left);
    }
    WorldStats::Stats resources = {0, 0, 0, 0, 0, 0};
    reader.read(resources);
    this->_stats.loadResources(resources);

    _Info("Game state loaded from file '" + path + "' successfully.");

    return true;
}

std::shared_ptr<SW::BuildingConfig> SW::GameLogic::queryConfig(const std::string & name) const {
    auto iterator = this->_building_configs.find(this->_selected_config);
    assert(iterator != std::end(this->_building_configs));
    return iterator->second;
}

uint16_t SW::GameLogic::convertToGameCoordinate(uint16_t coordinate) {
    return floor((double)coordinate / (GameLogic::TILE_SIZE + GameLogic::TILE_SPACING));
}

uint16_t SW::GameLogic::convertFromGameCoordinate(uint16_t coordinate) {
    return (uint16_t)(GameLogic::TILE_SPACING + (GameLogic::TILE_SIZE + GameLogic::TILE_SPACING) * coordinate);
}

SW::Position SW::GameLogic::convertToGameCoordinates(SW::Position position) {
    return {
            GameLogic::convertToGameCoordinate(position.x),
            GameLogic::convertToGameCoordinate(position.y)
    };
}

SW::Position SW::GameLogic::convertFromGameCoordinates(SW::Position position) {
    return {
            GameLogic::convertFromGameCoordinate(position.x),
            GameLogic::convertFromGameCoordinate(position.y)
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

uint32_t SW::GameLogic::buildingClicked(SW::Position position) {
    for (const auto & building : this->_buildings) {
        if (building.second->overlapsPoint(position)) {
            return building.first;
        }
    }
    return 0;
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
    // Handle action keys
    switch (code) {
        case SDLK_n:
            // Start new game
            this->clearGameState();
            this->start();
            break;
        case SDLK_s:
            // Save game state
            assert(this->save("savegame.bin"));
            break;
        case SDLK_l:
            // Load existing game state
            assert(this->load("savegame.bin"));
            break;
        default:
            break;
    }

    // Handle building keys
    auto iterator = this->_building_configs_bindings.find(code);
    if (iterator != end(this->_building_configs_bindings)) {
        this->_selected_config = iterator->second;
        _Info("Selected building '" + iterator->second + "'.");
    }
}

void SW::GameLogic::handleMouseClick(const SDL_MouseButtonEvent & click) {
    if (!this->_running) {
        return;
    }
    switch (click.button) {
        case SDL_BUTTON_LEFT:
            this->clickBuild(this->_selected_config, {(uint16_t)click.x, (uint16_t)click.y});
            break;
        case SDL_BUTTON_MIDDLE:
            // Upgrade existing building
            this->upgrade({(uint16_t)click.x, (uint16_t)click.y});
            break;
        case SDL_BUTTON_RIGHT:
            // Destroy existing building
            this->destroy({(uint16_t)click.x, (uint16_t)click.y});
            break;
        default:
            break;
    }
}

void SW::GameLogic::start() {
    this->_running = true;
}

void SW::GameLogic::stop() {
    this->_running = false;
}
