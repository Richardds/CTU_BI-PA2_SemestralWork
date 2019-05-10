#include "BuildingGenerator.h"
#include "Tools/BuildingConfigGenerator.h"
#include "Game/Objects/BuildingConfig.h"

void SW::BuildingGenerator::generate() {
    Tools::BuildingConfigGenerator::generate(
            BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("city_hall.bcfg"),
            "City Hall",
            3, 2,
            1,
            {202, 84, 98},

            {0, 1, 3, 0, 0, 0},
            {1, 1.8, 2.3, 1, 1, 1.3},

            {10, 50, 100, 0, 0, 30},
            {1, 1, 1.5, 1, 1, 1.25},

            {0, 5, 0, 5, 5, 3}
    );

    Tools::BuildingConfigGenerator::generate(
            BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("house.bcfg"),
            "House",
            1, 1,
            2,
            {84, 202, 188},

            {0, 1, 5, 0, 0, -1},
            {1, 1, 1.1, 1, 1, 1.25},

            {0, 0, 0, 0, 0, 10},
            {1, 1, 1, 1, 1, 1.5},

            {2, 15, 100, 10, 10, 30}
    );

    Tools::BuildingConfigGenerator::generate(
            BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("mine.bcfg"),
            "Mine",
            2, 2,
            4,
            {170, 170, 170},

            {1, 3, 10, 8, 0, -3},
            {1.5, 1.5, 1.5, 1.5, 1, 1.3},

            {5, 20, 150, 120, 0, 0},
            {1.25, 1.25, 1.25, 1.25, 1, 1},

            {0, 30, 150, 0, 10, 70}
    );

    Tools::BuildingConfigGenerator::generate(
            BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("lumber_mill.bcfg"),
            "Lumber Mill",
            2, 2,
            4,
            {205, 186, 150},

            {0, 0, 0, 0, 5, -3},
            {1, 1, 1, 1, 1.5, 1.3},

            {0, 0, 0, 0, 100, 0},
            {1, 1, 1, 1, 1.25, 1},

            {3, 25, 150, 5, 0, 40}
    );

    Tools::BuildingConfigGenerator::generate(
            BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("farm.bcfg"),
            "Farm",
            3, 3,
            4,
            {248, 185, 36},

            {0, 0, 0, 0, 0, 6},
            {1, 1, 1, 1, 1, 1.8},

            {0, 0, 0, 0, 20, 50},
            {1, 1, 1, 1, 1, 1.25},

            {0, 10, 50, 5, 5, 10}
    );
}
