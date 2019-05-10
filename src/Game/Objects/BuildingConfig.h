#ifndef SEMESTRALWORK_GENERICBUILDING_H
#define SEMESTRALWORK_GENERICBUILDING_H

#include <cassert>
#include <string>
#include <fstream>
#include "../../Core/core.h"
#include "../WorldStats.h"

namespace SW {
    /**
     * Holds building attributes and methods shared among all buildings of same type.
     */
    class BuildingConfig {
    public:
        /**
         * Constructor
         * @param config_name Configuration file name located in SW::BuildingConfig::BUILDINGS_CONFIG_PATH
         */
        explicit BuildingConfig(const std::string & config_name);
        /**
         * Loads configuration from file.
         * @param config_name Configuration file name located in SW::BuildingConfig::BUILDINGS_CONFIG_PATH
         * @return true on success, otherwise false
         */
        bool load(const std::string & config_name);
        /**
         * @return Configuration game title
         */
        std::string getTitle() const;
        /**
         * @return Configuration width in pixels
         */
        uint8_t getSizeX() const;
        /**
         * @return Configuration height in pixels
         */
        uint8_t getSizeY() const;
        /**
         * @return Configuration construction time in ticks
         */
        uint16_t getBuildTime() const;
        /**
         * @return Configuration color
         */
        SDL_Color getColor() const;
        /**
         * @return Configuration file name located in SW::BuildingConfig::BUILDINGS_CONFIG_PATH
         */
        std::string getName() const;
        /**
         * @return Configuration base of resources gain
         */
        const WorldStats::Stats & getResourcesGainBase() const;
        /**
         * @return Configuration dynamic modifier of resources gain
         */
        const WorldStats::StatsModifier & getResourcesGainModifier() const;
        /**
         * @return Configuration base of resources limit
         */
        const WorldStats::Stats & getResourcesLimitIncreaseBase() const;
        /**
         * @return Configuration dynamic modifier of resources limit
         */
        const WorldStats::StatsModifier & getResourcesLimitIncreaseModifier() const;
        /**
         * @return Configuration base of construction costs
         */
        const WorldStats::Stats & getBuildCostBase() const;

        /**
         * Path to folder of all configuration files
         */
        static const char * BUILDINGS_CONFIG_PATH;
        /**
         * Current configuration binary format version. Should be increased on every format update.
         */
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
