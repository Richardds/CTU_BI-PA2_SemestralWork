#ifndef SEMESTRALWORK_WORLDSTATS_H
#define SEMESTRALWORK_WORLDSTATS_H

#include <cmath>
#include "../Core/core.h"
#include "../System/Containers/IdentifyingCollection.h"

namespace SW {
    class Building;

    class WorldStats {
    public:
        struct Stats {
            int16_t gold;
            int16_t silver;
            int16_t copper;
            int16_t iron;
            int16_t wood;
            int16_t grain;
        };
        struct StatsModifier {
            float gold;
            float silver;
            float copper;
            float iron;
            float wood;
            float grain;
        };
        friend struct WorldStats::Stats;
        WorldStats();
        explicit WorldStats(const Stats & resources);
        bool increaseGold(int16_t amount);
        bool increaseSilver(int16_t amount);
        bool increaseCopper(int16_t amount);
        bool increaseIron(int16_t amount);
        bool increaseWood(int16_t amount);
        bool increaseGrain(int16_t amount);
        void updateResourcesFromBuildings(const IdentifyingCollection<std::shared_ptr<Building>> & buildings);
        bool tick();
        std::string toString();

    private:
        template<typename T> bool increaseFunction(T & var, T amount, T limit);
        Stats _resources;
        Stats _resources_limit;
        Stats _resources_gain;
    };
}

#endif
