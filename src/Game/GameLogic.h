#ifndef SEMESTRALWORK_GAMELOGIC_H
#define SEMESTRALWORK_GAMELOGIC_H

#include <cassert>
#include <algorithm>
#include <map>
#include "../Core/Renderer.h"
#include "../Core/core.h"
#include "WorldStats.h"
#include "Objects/BuildingConfig.h"
#include "Objects/Building.h"
#include "../System/Containers/IdentifyingCollection.h"

namespace SW {
    class GameLogic {
    public:
        struct BuildingConfigKeyboardBinding {
            int16_t key_code;
            std::string config_name;
        };
        explicit GameLogic(const Window & window);
        ~GameLogic();
        void clearGameState();
        void process(const Renderer & renderer);
        void handleEvent(const SDL_Event & event);
        bool build(const std::string & config_name, Position position, uint32_t * building_id = nullptr);
        bool destroy(Position position);
        bool save(const std::string & path);
        bool load(const std::string & path);

        static uint16_t convertToGameCoordinate(uint16_t coordinate);
        static uint16_t convertFromGameCoordinate(uint16_t coordinate);
        static Position convertToGameCoordinates(Position position);
        static Position convertFromGameCoordinates(Position position);

        static const uint32_t TICK_DEFAULT = 2000;
        static const uint16_t TILE_SIZE = 40;
        static const uint16_t TILE_SPACING = 5;
        static const uint8_t SUPPORTED_GAME_STATE_VERSION = 1;

    private:
        const Window & _window;
        uint32_t _tick;
        uint32_t _tick_last;
        uint32_t _game_time;
        SDL_Point _cursor_position;
        WorldStats _stats;
        IdentifyingCollection<std::shared_ptr<Building>> _buildings;
        std::map<std::string, BuildingConfig *> _building_configs;
        std::map<int16_t , std::string> _building_configs_bindings;
        std::string _selected_config;

        bool tick();
        void handleKeyboard(SDL_Keycode code);
        void handleMouseClick(const SDL_MouseButtonEvent & click);
        void loadBuildingConfigs(std::initializer_list<BuildingConfigKeyboardBinding> bindings);
    };
}

#endif
