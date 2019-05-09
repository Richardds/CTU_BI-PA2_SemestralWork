#ifndef SEMESTRALWORK_BUILDINGCONFIGGENERATOR_H
#define SEMESTRALWORK_BUILDINGCONFIGGENERATOR_H

#include <string>
#include <fstream>
#include "../Core/core.h"
#include "../Game/WorldStats.h"

namespace SW {
    namespace Tools {
        class BuildingConfigGenerator {
        public:
            static bool generate(const std::string & path,
                                 const std::string & title,
                                 uint8_t size_x,
                                 uint8_t size_y,
                                 uint16_t build_time,
                                 SDL_Color color,
                                 const WorldStats::Stats & resources_gain_base,
                                 const WorldStats::StatsModifier & resources_gain_modifier,
                                 const SW::WorldStats::Stats & resources_limit_increase_base,
                                 const WorldStats::StatsModifier & resources_limit_increase_modifier,
                                 const WorldStats::Stats & build_cost_base);
        };
    }
}

#endif
