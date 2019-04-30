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
        const std::string & getTitle() const;
        uint8_t getSizeX() const;
        uint8_t getSizeY() const;
        SDL_Color getColor() const;
        const WorldStats::Stats & getResourcesGainBase() const;
        const WorldStats::StatsModifier & getResourcesGainModifier() const;

        static constexpr const char * BUILDINGS_CONFIG_PATH = "data/buildings/";
        static const uint8_t SUPPORTED_VERSION = 1;

    private:
        std::string _title;
        uint8_t _size_x;
        uint8_t _size_y;
        SDL_Color _color;
        const WorldStats::Stats _resources_gain_base;
        const WorldStats::StatsModifier _resources_gain_modifier;
    };
}

#endif
