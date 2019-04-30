#ifndef SEMESTRALWORK_BUILDING_H
#define SEMESTRALWORK_BUILDING_H

#include <cmath>
#include "../../Graphics/Rectangle.h"
#include "BuildingConfig.h"

namespace SW {
    class Building : public Rectangle {
    public:
        explicit Building(const BuildingConfig * config, SDL_Point position);
        const BuildingConfig * getConfig() const;
        void updateResourcesLimit();
        void updateResourcesGain();
        void applyBuildingResourcesLimit(WorldStats::Stats & resources);
        void applyBuildingResourcesGain(WorldStats::Stats & resources);
        uint8_t getLevel() const;
        void setLevel(uint8_t level);

    private:
        const BuildingConfig * _config;
        WorldStats::Stats _resources_limit;
        WorldStats::Stats _resources_gain;
        uint8_t _level;
    };
}

#endif
