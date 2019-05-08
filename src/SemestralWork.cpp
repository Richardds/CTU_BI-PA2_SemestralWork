#include "SemestralWork.h"

SW::SemestralWork::SemestralWork() : _window(Window::DEFAULT_WIDTH, Window::DEFAULT_HEIGHT), _game(_window), _close(false) {
    this->_window.setTitle("BI-PA2: Semestral work | Richard Boldis (boldiric)");
}

SW::SemestralWork::~SemestralWork() {
    this->destroy();
}

bool SW::SemestralWork::initialize() {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        _Error("Failed to initialize SDL video subsystem!");
        return false;
    }
    // Initialize window
    if (!this->_window.initialize()) {
        _Error("Failed to initialize window!");
        return false;
    }
    // Initialize renderer
    if (!this->_renderer.initialize(this->_window)) {
        _Error("Failed to initialize renderer!");
        return false;
    }
    this->_close = false;
    return true;
}

void SW::SemestralWork::destroy() {
    this->_renderer.destroy();
    this->_window.destroy();
    SDL_Quit();
}

bool SW::SemestralWork::closeRequested() {
    return this->_close;
}

void SW::SemestralWork::loop() {
    this->_renderer.prepare();
    this->handleEvent();
    this->_game.process(this->_renderer);
    this->_renderer.update();
}

void SW::SemestralWork::handleEvent() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            // User requested application close
            case SDL_QUIT:
                this->_close = true;
                break;
            default:
                this->_game.handleEvent(event);
                break;
        }
    }
}
