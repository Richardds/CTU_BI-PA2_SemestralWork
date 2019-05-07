#ifndef SEMESTRALWORK_GAMELOGIC_H
#define SEMESTRALWORK_GAMELOGIC_H

#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include "../Core/Renderer.h"
#include "../Core/core.h"
#include "WorldStats.h"
#include "Objects/BuildingConfig.h"
#include "Objects/Building.h"

namespace SW {
    class GameLogic {
    public:
        struct BuildingConfigKeyboardBinding {
            int16_t key_code;
            std::string config_name;
        };
        GameLogic();
        ~GameLogic();
        void handleEvent(const SDL_Event & event);
        void handleKeyboard(SDL_Keycode code);
        void handleMouseMotion(const SDL_MouseMotionEvent & motion);
        void process(const Renderer & renderer);

        // Game methods
        bool build(const std::string & config_name, SDL_Point position);

        static SDL_Point convertToGameCoordinates(SDL_Point point);
        static SDL_Point convertFromGameCoordinates(SDL_Point point);
        static SDL_Point normalizeCoordinates(SDL_Point point);

        static const uint32_t TICK_DEFAULT = 5000;
        static const int TILE_SIZE = 40;
        static const int TILE_SPACING = 5;

    private:
        void loadBuildingConfigs(std::initializer_list<BuildingConfigKeyboardBinding> bindings);
        bool tick();
        uint32_t _tick;
        uint32_t _tick_last;
        SDL_Point _cursor_position;
        WorldStats _stats;
        std::map<std::string, BuildingConfig *> _building_configs;
        std::map<int16_t , std::string> _building_configs_bindings;
        std::string _selected_config;
        std::vector<Building *> _buildings;
    };
}

#endif
