#ifndef SEMESTRALWORK_BUILDING_H
#define SEMESTRALWORK_BUILDING_H

#include <cmath>
#include "../../Graphics/Rectangle.h"
#include "BuildingConfig.h"

namespace SW {
    /**
     * Main game building entity.
     */
    class Building : public Rectangle, public Exportable {
    public:
        /**
         * Constructor
         * @param config Pointer to building configuration
         * @param game_position Game coordinates
         */
        Building(const std::shared_ptr<const BuildingConfig> & config, Position game_position);
        /**
         * @return Pointer to building configuration
         */
        const std::shared_ptr<const BuildingConfig> getConfig() const;
        /**
         * Refreshes resources limit cache of building.
         */
        void updateResourcesLimit();
        /**
         * Refreshes resources gain cache of building.
         */
        void updateResourcesGain();
        /**
         * Applies resources limit of building to given resources
         * @param resources Reference to resources limit
         */
        void applyBuildingResourcesLimit(WorldStats::Stats & resources);
        /**
         * Applies resources gain of building to given resources
         * @param resources Reference to resources gain
         */
        void applyBuildingResourcesGain(WorldStats::Stats & resources);
        /**
         * @return Current game x coordinate
         */
        int getGamePositionX() const;
        /**
         * Sets game coordinate x.
         * @param game_position_x Game coordinate x
         */
        void setGamePositionX(int game_position_x);
        /**
         * @return Current game y coordinate
         */
        int getGamePositionY() const;
        /**
         * Sets game coordinate y.
         * @param game_position_y Game coordinate y
         */
        void setGamePositionY(int game_position_y);
        /**
         * @return Level of building
         */
        uint8_t getLevel() const;
        /**
         * Sets level of building
         * @param level
         */
        void setLevel(uint8_t level);
        /**
         * Increases level of building by one.
         * @return false if maximum level was reached, otherwise true
         */
        bool levelUp();
        /**
         * @return true if building status is active, otherwise false
         */
        bool isBuilt() const;
        /**
         * Sets time in game ticks of construction finish.
         * @param ticks Game ticks
         */
        void setBuiltInTicks(uint16_t ticks);
        /**
         * Triggers building update procedures.
         */
        void tick();
        /**
         * @return Population of building
         */
        uint16_t getPopulation();

        /**
         * Draws building to screen.
         * @param renderer SDL_Renderer wrapper
         */
        void draw(const Renderer & renderer) const override;
        /**
         * Packs and write building state to binary stream.
         * @param reader
         */
        void writeToBinaryWriter(BinaryWriter & reader) const override;

        /**
         * Maximum building level
         */
        static const uint8_t MAX_LEVEL = 5;
        /**
         * Default building construction color
         */
        static const SDL_Color CONSTRUCTION_COLOR;
        /**
         * Default building level badge color
         */
        static const SDL_Color LEVEL_BADGE_COLOR;

    private:
        const std::shared_ptr<const BuildingConfig> _config;
        Position _game_position;
        WorldStats::Stats _resources_limit;
        WorldStats::Stats _resources_gain;
        uint8_t _level;
        uint16_t _construction_time_left;
        bool _built;
    };
}

#endif
