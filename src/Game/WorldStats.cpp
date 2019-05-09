#include "WorldStats.h"
#include "Objects/Building.h"

SW::WorldStats::WorldStats() : _population(0), _resources(), _resources_limit(), _resources_gain() {
    this->reset();
}

bool SW::WorldStats::increaseGold(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.gold, amount, this->_resources_limit.gold);
}

bool SW::WorldStats::increaseSilver(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.silver, amount, this->_resources_limit.silver);
}

bool SW::WorldStats::increaseCopper(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.copper, amount, this->_resources_limit.copper);
}

bool SW::WorldStats::increaseIron(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.iron, amount, this->_resources_limit.iron);
}

bool SW::WorldStats::increaseWood(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.wood, amount, this->_resources_limit.wood);
}

bool SW::WorldStats::increaseGrain(int16_t amount) {
    return WorldStats::increaseFunction(this->_resources.grain, amount, this->_resources_limit.grain);
}

void SW::WorldStats::updateResourcesFromBuildings(const IdentifyingCollection<std::shared_ptr<Building>> & buildings) {
    this->_population = 0;
    this->_resources_limit = {0};
    this->_resources_gain = {0};
    for (const auto & building : buildings) {
        // Process built buildings only
        if (building.second->isBuilt()) {
            this->_population += building.second->getPopulation();
            building.second->applyBuildingResourcesLimit(this->_resources_limit);
            building.second->applyBuildingResourcesGain(this->_resources_gain);
        }
    }
}

bool SW::WorldStats::tick() {
    this->increaseGold(this->_resources_gain.gold);
    this->increaseSilver(this->_resources_gain.silver);
    this->increaseCopper(this->_resources_gain.copper);
    this->increaseIron(this->_resources_gain.iron);
    this->increaseWood(this->_resources_gain.wood);
    this->increaseGrain(this->_resources_gain.grain);
    return this->_resources.grain > 0 || this->_resources_gain.grain > 0;
}

void SW::WorldStats::reset() {
    this->_population = 0;
    this->_resources = {0};
    this->_resources_gain = {0};
    this->_resources_limit = {0};
    this->_resources.grain = 5;
}

void SW::WorldStats::loadResources(const SW::WorldStats::Stats & resources) {
    this->_resources = resources;
}

std::string SW::WorldStats::toString(bool population_only) {
    if (population_only) {
        return "Population: " + std::to_string(this->_population);
    }
    return "Population: " + std::to_string(this->_population) + " | "
           + "Gold: " + std::to_string(this->_resources.gold) + " (" + toStringShowSign(this->_resources_gain.gold) + ") | "
           + "Silver: " + std::to_string(this->_resources.silver) + " (" + toStringShowSign(this->_resources_gain.silver) + ") | "
           + "Copper: " + std::to_string(this->_resources.copper) + " (" + toStringShowSign(this->_resources_gain.copper) + ") | "
           + "Iron: " + std::to_string(this->_resources.iron) + " (" + toStringShowSign(this->_resources_gain.iron) + ") | "
           + "Wood: " + std::to_string(this->_resources.wood) + " (" + toStringShowSign(this->_resources_gain.wood) + ") | "
           + "Grain: " + std::to_string(this->_resources.grain) + " (" + toStringShowSign(this->_resources_gain.grain) + ")";
}

template<typename T>
bool SW::WorldStats::increaseFunction(T & var, T amount, T limit) {
    if (amount > 0) {
        if (var + amount > limit) {
            var += limit - var;
            return true;
        }
    } else if (amount < 0) {
        if (var + amount < 0) {
            var = 0;
            return false;
        }
    }
    var += amount;
    return true;
}

void SW::WorldStats::writeToBinaryWriter(SW::BinaryWriter & writer) const {
    writer.write(this->_resources);
}
