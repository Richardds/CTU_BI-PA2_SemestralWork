#include "BuildingConfigGenerator.h"
#include "../System/BinaryWriter.h"
#include "../Game/Objects/BuildingConfig.h"

bool SW::Tools::BuildingConfigGenerator::generate(const std::string & path,
                                                  const std::string & title,
                                                  uint8_t size_x,
                                                  uint8_t size_y,
                                                  SDL_Color color,
                                                  const SW::WorldStats::Stats & resources_gain_base,
                                                  const WorldStats::StatsModifier & resources_gain_modifier,
                                                  const SW::WorldStats::Stats & resources_limit_increase_base,
                                                  const WorldStats::StatsModifier & resources_limit_increase_modifier) {
    _Internal("Generating building config '" + path + "'.");
    BinaryWriter writer;
    if (!writer.open(path)) {
        _Error("Failed to generate building config '" + path + "'.");
        return false;
    }
    writer.write(Magic::BUILDING_CONFIG);
    uint8_t version = BuildingConfig::SUPPORTED_VERSION;
    writer.write(version);
    writer.writeString(title);
    writer.write(size_x);
    writer.write(size_y);
    writer.write(color);
    writer.write(resources_gain_base);
    writer.write(resources_gain_modifier);
    writer.write(resources_limit_increase_base);
    writer.write(resources_limit_increase_modifier);
    writer.close();
    _Internal("Building config '" + path + "' successfully generated.");
    return true;
}
