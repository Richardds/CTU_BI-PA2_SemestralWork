#define SDL_MAIN_HANDLED

#include "SemestralWork.h"
#include "Tools/BuildingConfigGenerator.h"

#include "generate.cpp"

using namespace SW;

int main() {
    // Generate default building types for project demonstration
    SW::generate();

    SemestralWork application;

    // Initialize application
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
