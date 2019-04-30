#include "Tools/BuildingConfigGenerator.h"
#include "Game/Objects/BuildingConfig.h"

namespace SW {
    void generate() {
        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("city_hall.bcfg"),
                "City Hall",
                3, 2,
                {255, 0, 0},

                {.gold = 0, .silver = 2, .copper = 33, .iron = 0, .wood = 0, .grain = -3},
                {1, 1.8, 2.3, 1, 1, 1.3},

                {.gold = 10, .silver = 25, .copper = 50, .iron = 0, .wood = 0, .grain = 30},
                {1, 1, 2, 1, 1, 1.25}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("house.bcfg"),
                "House",
                1, 1,
                {0, 255, 0},

                {.gold = 0, .silver = 0, .copper = 2, .iron = 0, .wood = 0, .grain = -1},
                {1, 1, 1.1, 1, 1, 1.5},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 0, .grain = 10},
                {1, 1, 1, 1, 1, 1.5}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("mine.bcfg"),
                "Mine",
                2, 2,
                {0, 0, 255},

                {.gold = 2, .silver = 12, .copper = 55, .iron = 17, .wood = 0, .grain = -4},
                {1.5, 1.5, 1.5, 1.5, 1, 1.3},

                {.gold = 15, .silver = 25, .copper = 35, .iron = 45, .wood = 0, .grain = 0},
                {1.25, 1.25, 1.25, 1.25, 1, 1}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("lumber_mill.bcfg"),
                "Lumber Mill",
                2, 2,
                {255, 0, 255},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 15, .grain = -3},
                {1, 1, 1, 1, 1.5, 1.3},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 50, .grain = 0},
                {1, 1, 1, 1, 1.25, 1}
        );

        Tools::BuildingConfigGenerator::generate(
                BuildingConfig::BUILDINGS_CONFIG_PATH + std::string("farm.bcfg"),
                "Farm",
                4, 5,
                {255, 255, 0},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 0, .grain = 18},
                {1, 1, 1, 1, 1, 1.8},

                {.gold = 0, .silver = 0, .copper = 0, .iron = 0, .wood = 15, .grain = 100},
                {1, 1, 1, 1, 1, 1.25}
        );
    }
}
