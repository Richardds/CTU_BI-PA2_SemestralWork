#include <iostream>
#include "SemestralWork.h"

using namespace SW;

int main() {
    SemestralWork application;

    if (!application.initialize()) {
        std::cerr << "Failed to initialize application!" << std::endl;
        return 1;
    }

    application.clearDisplay();

    while (!application.closeRequested()) {
        application.loop();
    }

    application.destroy();

    return 0;
}
