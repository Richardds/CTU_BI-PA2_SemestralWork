#ifndef SEMESTRALWORK_GENERICBUILDING_H
#define SEMESTRALWORK_GENERICBUILDING_H

#include <cassert>
#include <string>
#include <fstream>
#include "../../Core/core.h"
#include "../WorldStats.h"

namespace SW {
    class BuildingConfig {
    public:
        explicit BuildingConfig(const std::string & config_name);
        bool load(const std::string & config_name);
        std::string getTitle() const;
        uint8_t getSizeX() const;
        uint8_t getSizeY() const;
        uint16_t getBuildTime() const;
        SDL_Color getColor() const;
        std::string getName() const;
        const WorldStats::Stats & getResourcesGainBase() const;
        const WorldStats::StatsModifier & getResourcesGainModifier() const;
        const WorldStats::Stats & getResourcesLimitIncreaseBase() const;
        const WorldStats::StatsModifier & getResourcesLimitIncreaseModifier() const;
        const WorldStats::Stats & getBuildCostBase() const;

        static const char * BUILDINGS_CONFIG_PATH;
        static const uint8_t SUPPORTED_VERSION = 1;

    private:
        std::string _name;
        std::string _title;
        uint8_t _size_x;
        uint8_t _size_y;
        uint16_t _build_time;
        SDL_Color _color;
        const WorldStats::Stats _resources_gain_base;
        const WorldStats::StatsModifier _resources_gain_modifier;
        const WorldStats::Stats _resources_limit_increase_base;
        const WorldStats::StatsModifier _resources_limit_increase_modifier;
        const WorldStats::Stats _build_cost;
    };
}

#endif
