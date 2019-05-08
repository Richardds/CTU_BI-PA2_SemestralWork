#ifndef SEMESTRALWORK_BUILDING_H
#define SEMESTRALWORK_BUILDING_H

#include <cmath>
#include "../../Graphics/Rectangle.h"
#include "BuildingConfig.h"

namespace SW {
    class Building : public Rectangle, public Exportable {
    public:
        explicit Building(const BuildingConfig * config, Position game_position);
        const BuildingConfig * getConfig() const;
        void updateResourcesLimit();
        void updateResourcesGain();
        void applyBuildingResourcesLimit(WorldStats::Stats & resources);
        void applyBuildingResourcesGain(WorldStats::Stats & resources);
        int getGamePositionX() const;
        void setGamePositionX(int game_position_x);
        int getGamePositionY() const;
        void setGamePositionY(int game_position_y);
        uint8_t getLevel() const;
        void setLevel(uint8_t level);

        void writeToBinaryWriter(BinaryWriter & reader) const override;

    private:
        const BuildingConfig * _config;
        Position _game_position;
        WorldStats::Stats _resources_limit;
        WorldStats::Stats _resources_gain;
        uint8_t _level;
    };
}

#endif
