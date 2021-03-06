#include "BuildingConfig.h"
#include "../../System/BinaryReader.h"

const char * SW::BuildingConfig::BUILDINGS_CONFIG_PATH = "buildings/";

SW::BuildingConfig::BuildingConfig(const std::string & config_name)
    : _name(config_name),
      _size_x(1),
      _size_y(1),
      _build_time(0),
      _color(),
      _resources_gain_base(),
      _resources_gain_modifier(),
      _resources_limit_increase_base(),
      _resources_limit_increase_modifier(),
      _build_cost() {
    assert(this->load(config_name));
}

bool SW::BuildingConfig::load(const std::string & config_name) {
    _Info("Loading building config file '" + config_name + "'.");
    BinaryReader reader;

    if (!reader.open(BuildingConfig::BUILDINGS_CONFIG_PATH + config_name + ".bcfg")) {
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
    reader.read(this->_build_time);
    reader.read(this->_color);
    reader.read(this->_resources_gain_base);
    reader.read(this->_resources_gain_modifier);
    reader.read(this->_resources_limit_increase_base);
    reader.read(this->_resources_limit_increase_modifier);
    reader.read(this->_build_cost);
    _Info("Building config file '" + config_name + "' loaded successfully.");
    return true;
}

std::string SW::BuildingConfig::getName() const {
    return this->_name;
}

std::string SW::BuildingConfig::getTitle() const {
    return this->_title;
}

uint8_t SW::BuildingConfig::getSizeX() const {
    return this->_size_x;
}

uint8_t SW::BuildingConfig::getSizeY() const {
    return this->_size_y;
}

uint16_t SW::BuildingConfig::getBuildTime() const {
    return this->_build_time;
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

const SW::WorldStats::Stats & SW::BuildingConfig::getBuildCostBase() const {
    return this->_build_cost;
}
