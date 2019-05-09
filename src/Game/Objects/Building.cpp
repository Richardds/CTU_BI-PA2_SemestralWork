#include "Building.h"
#include "../GameLogic.h"

const SDL_Color SW::Building::CONSTRUCTION_COLOR = {200, 200, 200};
const SDL_Color SW::Building::LEVEL_BADGE_COLOR = {255, 252, 37};

SW::Building::Building(const std::shared_ptr<const BuildingConfig> & config, Position game_position)
    : Rectangle(
            config->getSizeX() * GameLogic::TILE_SIZE + (config->getSizeX() - 1) * GameLogic::TILE_SPACING,
            config->getSizeY() * GameLogic::TILE_SIZE + (config->getSizeY() - 1) * GameLogic::TILE_SPACING,
            GameLogic::convertFromGameCoordinates(game_position),
            Building::CONSTRUCTION_COLOR),
      _config(config),
      _game_position(game_position),
      _resources_limit(),
      _resources_gain(),
      _level(0),
      _construction_time_left(config->getBuildTime()),
      _built(false) {
    this->setLevel(1); // Trigger resources update
}

const std::shared_ptr<const SW::BuildingConfig> SW::Building::getConfig() const {
    return this->_config;
}

void SW::Building::updateResourcesLimit() {
    const WorldStats::Stats & resources_limit_increase_base = this->_config->getResourcesLimitIncreaseBase();
    const WorldStats::StatsModifier & resources_limit_increase_modifier = this->_config->getResourcesLimitIncreaseModifier();
    this->_resources_limit = {
            (int16_t)((float)resources_limit_increase_base.gold * (float)this->_level * resources_limit_increase_modifier.gold),
            (int16_t)((float)resources_limit_increase_base.silver * (float)this->_level * resources_limit_increase_modifier.silver),
            (int16_t)((float)resources_limit_increase_base.copper * (float)this->_level * resources_limit_increase_modifier.copper),
            (int16_t)((float)resources_limit_increase_base.iron * (float)this->_level * resources_limit_increase_modifier.iron),
            (int16_t)((float)resources_limit_increase_base.wood * (float)this->_level * resources_limit_increase_modifier.wood),
            (int16_t)((float)resources_limit_increase_base.grain * (float)this->_level * resources_limit_increase_modifier.grain)
    };
}

void SW::Building::updateResourcesGain() {
    const WorldStats::Stats & resources_gain_base = this->_config->getResourcesGainBase();
    const WorldStats::StatsModifier & resources_gain_modifier = this->_config->getResourcesGainModifier();
    this->_resources_gain = {
            (int16_t)((float)resources_gain_base.gold * (float)this->_level * resources_gain_modifier.gold),
            (int16_t)((float)resources_gain_base.silver * (float)this->_level * resources_gain_modifier.silver),
            (int16_t)((float)resources_gain_base.copper * (float)this->_level * resources_gain_modifier.copper),
            (int16_t)((float)resources_gain_base.iron * (float)this->_level * resources_gain_modifier.iron),
            (int16_t)((float)resources_gain_base.wood * (float)this->_level * resources_gain_modifier.wood),
            (int16_t)((float)resources_gain_base.grain * (float)this->_level * resources_gain_modifier.grain)
    };
}

void SW::Building::applyBuildingResourcesLimit(SW::WorldStats::Stats & resources) {
    resources.gold += this->_resources_limit.gold;
    resources.silver += this->_resources_limit.silver;
    resources.copper += this->_resources_limit.copper;
    resources.iron += this->_resources_limit.iron;
    resources.wood += this->_resources_limit.wood;
    resources.grain += this->_resources_limit.grain;
}

void SW::Building::applyBuildingResourcesGain(SW::WorldStats::Stats & resources) {
    resources.gold += this->_resources_gain.gold;
    resources.silver += this->_resources_gain.silver;
    resources.copper += this->_resources_gain.copper;
    resources.iron += this->_resources_gain.iron;
    resources.wood += this->_resources_gain.wood;
    resources.grain += this->_resources_gain.grain;
}

int SW::Building::getGamePositionX() const {
    return this->_game_position.x;
}

void SW::Building::setGamePositionX(int game_position_x) {
    this->_position.x = GameLogic::convertFromGameCoordinate(game_position_x);
    this->_game_position.x = game_position_x;
}

int SW::Building::getGamePositionY() const {
    return this->_game_position.y;
}

void SW::Building::setGamePositionY(int game_position_y) {
    this->_position.y = GameLogic::convertFromGameCoordinate(game_position_y);
    this->_game_position.y = game_position_y;
}

uint8_t SW::Building::getLevel() const {
    return this->_level;
}

void SW::Building::setLevel(uint8_t level) {
    this->_level = level;
    this->updateResourcesLimit();
    this->updateResourcesGain();
}

bool SW::Building::levelUp() {
    if (this->_level != Building::MAX_LEVEL) {
        // Use setter to trigger resources update
        this->setLevel(this->_level + 1);
        return true;
    }
    return false;
}

void SW::Building::writeToBinaryWriter(SW::BinaryWriter & writer) const {
    writer.writeString(this->getConfig()->getName());
    writer.write(this->_game_position);
    writer.write(this->_level);
    writer.write(this->_construction_time_left);
}

bool SW::Building::isBuilt() const {
    return this->_built;
}

void SW::Building::setBuiltInTicks(uint16_t ticks) {
    if (ticks == 0) {
        this->_built = true;
        this->_color = this->getConfig()->getColor();
        return;
    }
    this->_built = false;
    this->_construction_time_left = ticks;
    this->_color = Building::CONSTRUCTION_COLOR;
}

void SW::Building::tick() {
    // Update build status
    if (!this->_built && this->_construction_time_left != 0) {
        this->_construction_time_left--;
        if (this->_construction_time_left == 0) {
            this->_built = true;
        }
    }
    // Update building color
    if (this->_built) {
        this->_color = this->getConfig()->getColor();
    }
}

void SW::Building::draw(const SW::Renderer & renderer) const {
    // Render default rectangle
    Rectangle::draw(renderer);
    // Render building level badges
    uint16_t x = this->_position.x;
    uint16_t y = this->_position.y;
    Rectangle rectangle(10, 10, {0, 0}, Building::LEVEL_BADGE_COLOR);
    for (uint8_t i = 1; i < this->_level; i++) {
        rectangle.setPosition({(uint16_t) (x + 5), (uint16_t) (y + 5)});
        rectangle.draw(renderer);
        if (i % 2 == 0) {
            x += 15;
            y -= 30;
        }
        y += 15;
    }
}

uint16_t SW::Building::getPopulation() {
    if (this->_config->getName() == "house") {
        return floor(2 * this->_level * 1.5);
    }
    return 0;
}
