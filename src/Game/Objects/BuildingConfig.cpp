#include "BuildingConfig.h"
#include "../../System/BinaryReader.h"

SW::BuildingConfig::BuildingConfig(const std::string & config_name)
    : _size_x(1),
      _size_y(1),
      _color(),
      _resources_gain_base(),
      _resources_gain_modifier(),
      _resources_limit_increase_base(),
      _resources_limit_increase_modifier() {
    assert(this->load(config_name));
}

bool SW::BuildingConfig::load(const std::string & config_name) {
    _Info("Loading building config file '" + config_name + "'.");
    BinaryReader reader;

    if (!reader.open(BUILDINGS_CONFIG_PATH + config_name + ".bcfg")) {
        _Error("Failed to open building config file '" + config_name + "'.");
        return false;
    }
    uint32_t magic;
    reader.read(magic);
    if (magic != Magic::BUILDING_CONFIG) {
        _Error("Magic mismatch in building config file '" + config_name + "'.");
        return false;
    }
    uint8_t version;
    reader.read(version);
    if (version != BuildingConfig::SUPPORTED_VERSION) {
        _Error("Unsupported building config file '" + config_name + "'.");
        return false;
    }
    reader.readString(this->_title);
    reader.read(this->_size_x);
    reader.read(this->_size_y);
    reader.read(this->_color);
    reader.read(this->_resources_gain_base);
    reader.read(this->_resources_gain_modifier);
    reader.read(this->_resources_limit_increase_base);
    reader.read(this->_resources_limit_increase_modifier);
    _Info("Building config file '" + config_name + "' loaded successfully.");
    return true;
}

const std::string & SW::BuildingConfig::getTitle() const {
    return this->_title;
}

uint8_t SW::BuildingConfig::getSizeX() const {
    return this->_size_x;
}

uint8_t SW::BuildingConfig::getSizeY() const {
    return this->_size_y;
}

SDL_Color SW::BuildingConfig::getColor() const {
    return this->_color;
}

const SW::WorldStats::Stats & SW::BuildingConfig::getResourcesGainBase() const {
    return this->_resources_gain_base;
}

const SW::WorldStats::StatsModifier & SW::BuildingConfig::getResourcesGainModifier() const {
    return this->_resources_gain_modifier;
}

const SW::WorldStats::Stats & SW::BuildingConfig::getResourcesLimitIncreaseBase() const {
    return this->_resources_limit_increase_base;
}

const SW::WorldStats::StatsModifier & SW::BuildingConfig::getResourcesLimitIncreaseModifier() const {
    return this->_resources_limit_increase_modifier;
}
