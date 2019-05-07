#include "Building.h"
#include "../GameLogic.h"

SW::Building::Building(const BuildingConfig * config, SDL_Point position)
    : Rectangle(
            config->getSizeX() * GameLogic::TILE_SIZE,
            config->getSizeY() * GameLogic::TILE_SIZE,
            GameLogic::convertFromGameCoordinates(position),
            config->getColor()),
      _config(config),
      _resources_limit(),
      _resources_gain(),
      _level(1) {
    this->setLevel(1); // TODO: Load building level from save game
}

const SW::BuildingConfig * SW::Building::getConfig() const {
    return this->_config;
}

void SW::Building::updateResourcesLimit() {
    const WorldStats::Stats & resources_limit_increase_base = this->_config->getResourcesLimitIncreaseBase();
    const WorldStats::StatsModifier & resources_limit_increase_modifier = this->_config->getResourcesLimitIncreaseModifier();
    this->_resources_limit = {
            .gold = (int16_t)((float)resources_limit_increase_base.gold * (float)this->_level * resources_limit_increase_modifier.gold),
            .silver = (int16_t)((float)resources_limit_increase_base.silver * (float)this->_level * resources_limit_increase_modifier.silver),
            .copper = (int16_t)((float)resources_limit_increase_base.copper * (float)this->_level * resources_limit_increase_modifier.copper),
            .iron = (int16_t)((float)resources_limit_increase_base.iron * (float)this->_level * resources_limit_increase_modifier.iron),
            .wood = (int16_t)((float)resources_limit_increase_base.wood * (float)this->_level * resources_limit_increase_modifier.wood),
            .grain = (int16_t)((float)resources_limit_increase_base.grain * (float)this->_level * resources_limit_increase_modifier.grain)
    };
}

void SW::Building::updateResourcesGain() {
    const WorldStats::Stats & resources_gain_base = this->_config->getResourcesGainBase();
    const WorldStats::StatsModifier & resources_gain_modifier = this->_config->getResourcesGainModifier();
    this->_resources_gain = {
            .gold = (int16_t)((float)resources_gain_base.gold * (float)this->_level * resources_gain_modifier.gold),
            .silver = (int16_t)((float)resources_gain_base.silver * (float)this->_level * resources_gain_modifier.silver),
            .copper = (int16_t)((float)resources_gain_base.copper * (float)this->_level * resources_gain_modifier.copper),
            .iron = (int16_t)((float)resources_gain_base.iron * (float)this->_level * resources_gain_modifier.iron),
            .wood = (int16_t)((float)resources_gain_base.wood * (float)this->_level * resources_gain_modifier.wood),
            .grain = (int16_t)((float)resources_gain_base.grain * (float)this->_level * resources_gain_modifier.grain)
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

uint8_t SW::Building::getLevel() const {
    return this->_level;
}

void SW::Building::setLevel(uint8_t level) {
    this->_level = level;
    this->updateResourcesLimit();
    this->updateResourcesGain();
}
