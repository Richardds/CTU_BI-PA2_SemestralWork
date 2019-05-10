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
        /**
         * Building keyboard binding structure
         */
        struct BuildingConfigKeyboardBinding {
            int16_t key_code;
            std::string config_name;
        };
        /**
         * Constructor
         * @param window SDL_Window wrapper
         */
        explicit GameLogic(const Window & window);
        /**
         * Destructor
         */
        ~GameLogic();
        /**
         * Resets game time to zero, clears all buildings and resets stats.
         */
        void clearGameState();
        /**
         * Renders game scene to screen.
         * @param renderer SDL_Renderer wrapper
         */
        void process(const Renderer & renderer);
        /**
         * Handles application events.
         * @param event Event to be handled
         */
        void handleEvent(const SDL_Event & event);
        /**
         * Builds building if other buildings does not collide.
         * @param to_build Building to be built
         * @param building_id Returns built building identifier
         * @return true if building was successfully built, otherwise false
         */
        bool build(const Building & to_build, uint32_t * building_id = nullptr);
        /**
         * Dues same as SW::GameLogic::build plus check for/subtract required resources for construction.
         * @param config_name Configuration name
         * @param position Screen coordinates which will be converted to game coordinates
         * @param building_id Returns built building identifier
         * @return true if building was successfully built, otherwise false
         */
        bool clickBuild(const std::string & config_name, Position position, uint32_t * building_id = nullptr);
        /**
         * Forces building construction on game state load. Uses SW::GameLogic::build.
         * @param config_name Configuration name
         * @param position Game coordinates
         * @param building_id Returns built building identifier
         * @return true if building was successfully built, otherwise false
         */
        bool forceBuild(const std::string & config_name, Position position, uint32_t * building_id = nullptr);
        /**
         * Upgrades building on given screen coordinates.
         * @param position Screen coordinates
         * @return true if there was building on given coordinates and player had required resources for upgrade
         */
        bool upgrade(Position position);
        /**
         * Destroys building on given screen coordinates.
         * @param position Screen coordinates
         * @return true if there was building on given coordinates and player had required resources for destroy
         */
        bool destroy(Position position);
        /**
         * Saves game state to file.
         * @param path Game state path
         * @return true on success, otherwise false
         */
        bool save(const std::string & path);
        /**
         * Clears game state using SW::GameLogic::clearGameState and loads game state from file.
         * @param path Game state path
         * @return true on success, otherwise false
         */
        bool load(const std::string & path);
        /**
         * Looks for loaded configuration
         * @param name Configuration name
         * @return Pointer to building configuration
         */
        std::shared_ptr<BuildingConfig> queryConfig(const std::string & name) const;

        /**
         * Helper for screen to game coordinate conversion
         * @param coordinate Screen coordinate
         * @return Coordinate in game scale
         */
        static uint16_t convertToGameCoordinate(uint16_t coordinate);
        /**
         * Helper for game to screen coordinate conversion
         * @param coordinate Game coordinate
         * @return Coordinate in screen scale
         */
        static uint16_t convertFromGameCoordinate(uint16_t coordinate);
        /**
         * Helper for screen to game coordinates conversion
         * @param position Screen coordinates
         * @return Coordinates in game scale
         */
        static Position convertToGameCoordinates(Position position);
        /**
         * Helper for game to screen coordinates conversion
         * @param position Game coordinates
         * @return Coordinates in screen scale
         */
        static Position convertFromGameCoordinates(Position position);

        /**
         * Default game tick time in milliseconds
         */
        static const uint32_t TICK_DEFAULT = 2000;
        /**
         * Tile side size in pixels
         */
        static const uint16_t TILE_SIZE = 40;
        /**
         * Tile spacing in pixels
         */
        static const uint16_t TILE_SPACING = 5;
        /**
         * Building destroy refund modifier
         */
        static constexpr double REFUND_MODIFIER = 0.350;
        /**
         * Current game state binary format version. Should be increased on every format update.
         */
        static const uint8_t SUPPORTED_GAME_STATE_VERSION = 1;

    private:
        const Window & _window;
        bool _running;
        uint32_t _tick;
        uint32_t _tick_last;
        uint32_t _game_time;
        SDL_Point _cursor_position;
        WorldStats _stats;
        IdentifyingCollection<std::shared_ptr<Building>> _buildings;
        std::map<std::string, std::shared_ptr<BuildingConfig>> _building_configs;
        std::map<int16_t , std::string> _building_configs_bindings;
        std::string _selected_config;
        bool _dev_mode;
        bool _city_hall_built;

        /**
         * @return true on next game tick, otherwise false
         */
        bool tick();
        /**
         * Checks if there is building on given screen coordinates.
         * @param position Screen coordinates
         * @return building ID if there was building, otherwise 0
         */
        uint32_t buildingClicked(Position position);
        /**
         * Handles keyboard key press.
         * @param code Keyboard key identifier
         */
        void handleKeyDown(SDL_Keycode code);
        /**
         * Handles mouse click.
         * @param click Mouse click event
         */
        void handleMouseClick(const SDL_MouseButtonEvent & click);
        /**
         * Loads initial building configurations.
         * @param bindings List of keyboard bindings
         */
        void loadBuildingConfigs(std::initializer_list<BuildingConfigKeyboardBinding> bindings);
        /**
         * Resumes/starts game from stopped state.
         */
        void start();
        /**
         * Stops game processing. User cannot modify game scene.
         */
        void stop();
    };
}

#endif
