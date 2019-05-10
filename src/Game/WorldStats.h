#ifndef SEMESTRALWORK_WORLDSTATS_H
#define SEMESTRALWORK_WORLDSTATS_H

#include <cmath>
#include <ostream>
#include "../Core/core.h"
#include "../System/Containers/IdentifyingCollection.h"
#include "Exportable.h"

namespace SW {
    class Building;

    /**
     * Manages game all resources and stats.
     */
    class WorldStats : public Exportable {
    public:
        /**
         * Resources structure
         */
        struct Stats {
            /**
             * @return Resources converted to std::string
             */
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
            /**
             * Multiplies all resources attributes by given multiplier
             * @param modifier Number by which all resources are multiplied
             * @return Multiplied resources
             */
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
        /**
         * Stats multiplier structure. Usually used as relative modifier to resources.
         */
        struct StatsModifier {
            float gold;
            float silver;
            float copper;
            float iron;
            float wood;
            float grain;
        };
        friend struct WorldStats::Stats;
        /**
         * Constructor
         */
        WorldStats();
        /**
         * Increases gold resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseGold(int16_t amount);
        /**
         * Increases silver resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseSilver(int16_t amount);
        /**
         * Increases copper resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseCopper(int16_t amount);
        /**
         * Increases iron resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseIron(int16_t amount);
        /**
         * Increases wood resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseWood(int16_t amount);
        /**
         * Increases grain resources by given value. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param amount Increasing amount
         * @return true if overflow happened, otherwise false
         */
        bool increaseGrain(int16_t amount);
        /**
         * Increases all resources by another given resources. Does not overflow resources limit value
         * and also cannot drop bellow zero.
         * @param resources Increasing resources
         * @param invert_values Inverts input resources sign if true
         */
        void increaseResources(const WorldStats::Stats & resources, bool invert_values = false);
        /**
         * Iterates all given buildings and calculates resources gain and limit of current game tick.
         * Buildings under construction are ignored.
         * @param buildings Buildings to be iterated
         */
        void updateResourcesFromBuildings(const IdentifyingCollection<std::shared_ptr<Building>> & buildings);
        /**
         * Increases resources byt resources gain.
         * @return true if grain production is sufficient
         */
        bool tick();
        /**
         * Resets population, resources gain and limit to default values.
         */
        void reset();
        /**
         * Sets resources. Usually from saved game state.
         * @param resources
         */
        void loadResources(const Stats & resources);
        /**
         * Converts stats to std::string.
         * @param population_only Returns population only on true
         * @return Converted resources to string.
         */
        std::string toString(bool population_only = false);
        /**
         * Check if given resources are bellow current resources.
         * @param resources Resources to check
         * @return true if player has sufficient resources, otherwise false
         */
        bool validateSufficientResources(const WorldStats::Stats & resources);

        /**
         * Packs and write resources state to binary stream.
         * @param writer
         */
        void writeToBinaryWriter(BinaryWriter & writer) const override;

    private:
        /**
         * Increases given resource value by give amount. Limits modifying value by upper limit.
         * @tparam T
         * @param var Reference to modifying value
         * @param amount Value to be added to modifying value
         * @param limit Modifying value upper limit
         * @return true if overflow happened, otherwise false
         */
        template<typename T> bool increaseFunction(T & var, T amount, T limit);
        uint16_t _population;
        Stats _resources;
        Stats _resources_gain;
        Stats _resources_limit;
    };
}

#endif
