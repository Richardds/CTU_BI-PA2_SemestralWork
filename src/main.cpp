#define SDL_MAIN_HANDLED

#include "SemestralWork.h"
#include "Tools/BuildingConfigGenerator.h"
#include "BuildingGenerator.h"

/**
 * Default project namespace
 */
using namespace SW;

/**
 * Application entry point.
 * @return program status
 */
int main() {
    // Generate default building types for project demonstration
    SW::BuildingGenerator::generate();

    // Construct application backbone
    SemestralWork application;

    // Initialize application subsystems
    if (!application.initialize()) {
        _Error("Failed to initialize application!");
        return 1;
    }

    // Update application until termination is requested
    while (!application.closeRequested()) {
        application.loop();
    }

    // Clean up application resources
    application.destroy();

    return 0;
}
