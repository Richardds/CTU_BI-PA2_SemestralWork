#ifndef SEMESTRALWORK_WORLDSTATS_H
#define SEMESTRALWORK_WORLDSTATS_H

#include <cmath>
#include <ostream>
#include "../Core/core.h"
#include "../System/Containers/IdentifyingCollection.h"
#include "Exportable.h"

namespace SW {
    class Building;

    class WorldStats : public Exportable {
    public:
        struct Stats {
            std::string toString() {
                std::string output;
                if (this->gold > 0) {
                    output += std::to_string(this->gold) + " gold ";
                }
                if (this->silver > 0) {
                    output += std::to_string(this->silver) + " silver ";
                }
                if (this->copper > 0) {
                    output += std::to_string(this->copper) + " copper ";
                }
                if (this->iron > 0) {
                    output += std::to_string(this->iron) + " iron ";
                }
                if (this->wood > 0) {
                    output += std::to_string(this->wood) + " wood ";
                }
                if (this->grain > 0) {
                    output += std::to_string(this->grain) + " grain";
                }
                return output;
            }
            Stats operator*(double modifier) const {
                Stats stats = *this;
                stats.gold = (int16_t)ceil(stats.gold * modifier);
                stats.silver = (int16_t)ceil(stats.silver * modifier);
                stats.copper = (int16_t)ceil(stats.copper * modifier);
                stats.iron = (int16_t)ceil(stats.iron * modifier);
                stats.wood = (int16_t)ceil(stats.wood * modifier);
                stats.grain = (int16_t)ceil(stats.grain * modifier);
                return stats;
            }
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
        bool increaseGold(int16_t amount);
        bool increaseSilver(int16_t amount);
        bool increaseCopper(int16_t amount);
        bool increaseIron(int16_t amount);
        bool increaseWood(int16_t amount);
        bool increaseGrain(int16_t amount);
        void increaseResources(const WorldStats::Stats & resources, bool invert_values = false);
        void updateResourcesFromBuildings(const IdentifyingCollection<std::shared_ptr<Building>> & buildings);
        bool tick();
        void reset();
        void loadResources(const Stats & resources);
        std::string toString(bool population_only = false);
        bool validateSufficientResources(const WorldStats::Stats & resources);

        void writeToBinaryWriter(BinaryWriter & writer) const override;

    private:
        template<typename T> bool increaseFunction(T & var, T amount, T limit);
        uint16_t _population;
        Stats _resources;
        Stats _resources_gain;
        Stats _resources_limit;
    };
}

#endif
