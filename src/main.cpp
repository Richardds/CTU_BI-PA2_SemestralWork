#define SDL_MAIN_HANDLED

#include "SemestralWork.h"
#include "Tools/BuildingConfigGenerator.h"

#include "generate.cpp"

using namespace SW;

int main() {
    SW::generate();

    SemestralWork application;

    if (!application.initialize()) {
        _Error("Failed to initialize application!");
        return 1;
    }

    while (!application.closeRequested()) {
        application.loop();
    }

    application.destroy();

    return 0;
}
