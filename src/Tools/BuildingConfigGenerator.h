#ifndef SEMESTRALWORK_BUILDINGCONFIGGENERATOR_H
#define SEMESTRALWORK_BUILDINGCONFIGGENERATOR_H

#include <string>
#include <fstream>
#include "../Core/core.h"
#include "../Game/WorldStats.h"

namespace SW {
    namespace Tools {
        /**
         * Generates building binary configuration files.
         */
        class BuildingConfigGenerator {
        public:
            /**
             * Writes building binary configuration file by given attributes.
             * @param path Binary configuration file path
             * @param title Building title
             * @param size_x Building width in pixels
             * @param size_y Building height in pixels
             * @param build_time Building construction time in game ticks
             * @param color Building color
             * @param resources_gain_base Building resources gain base
             * @param resources_gain_modifier Building resources gain relative modifier
             * @param resources_limit_increase_base Building resources limit base
             * @param resources_limit_increase_modifier Building resources limit relative modifier
             * @param build_cost_base Building construction costs
             * @return true on success, otherwise false
             */
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
