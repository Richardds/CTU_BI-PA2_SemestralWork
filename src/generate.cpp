#include "Tools/BuildingConfigGenerator.h"
#include "Game/Objects/BuildingConfig.h"

namespace SW {
    void generate() {
        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("city_hall.bcfg"),
                "City Hall",
                3, 2,
                1,
                {202, 84, 98},

                {.gold = 0, .silver = 1, .copper = 3, .iron = 0, .wood = 0, .grain = 0},
                {1, 1.8, 2.3, 1, 1, 1.3},

                {.gold = 10, .silver = 50, .copper = 100, .iron = 0, .wood = 0, .grain = 50},
                {1, 1, 1.5, 1, 1, 1.25}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("house.bcfg"),
                "House",
                1, 1,
                2,
                {84, 202, 188},

                {.gold = 0, .silver = 1, .copper = 5, .iron = 0, .wood = 0, .grain = -1},
                {1, 1, 1.1, 1, 1, 1.5},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 0, .grain = 10},
                {1, 1, 1, 1, 1, 1.5}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("mine.bcfg"),
                "Mine",
                2, 2,
                4,
                {170, 170, 170},

                {.gold = 1, .silver = 3, .copper = 10, .iron = 8, .wood = 0, .grain = -3},
                {1.5, 1.5, 1.5, 1.5, 1, 1.3},

                {.gold = 5, .silver = 20, .copper = 150, .iron = 120, .wood = 0, .grain = 0},
                {1.25, 1.25, 1.25, 1.25, 1, 1}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("lumber_mill.bcfg"),
                "Lumber Mill",
                2, 2,
                4,
                {205, 186, 150},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 5, .grain = -3},
                {1, 1, 1, 1, 1.5, 1.3},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 100, .grain = 0},
                {1, 1, 1, 1, 1.25, 1}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("farm.bcfg"),
                "Farm",
                4, 5,
                4,
                {248, 185, 36},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 0, .grain = 5},
                {1, 1, 1, 1, 1, 1.8},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 20, .grain = 100},
                {1, 1, 1, 1, 1, 1.25}
        );
    }
}
