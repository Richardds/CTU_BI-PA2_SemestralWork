#include "SemestralWork.h"

SW::SemestralWork::SemestralWork() : _window(Window::DEFAULT_WIDTH, Window::DEFAULT_HEIGHT), _close(true) {
    this->_window.setTitle("BI-PA2: Semestral work | Richard Boldis (boldiric)");
}

SW::SemestralWork::~SemestralWork() {
    this->destroy();
}

bool SW::SemestralWork::initialize() {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return false;
    }
    // Initialize window
    if (!this->_window.initialize()) {
        return false;
    }
    // Initialize renderer
    if (!this->_renderer.initialize(this->_window)) {
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
    this->handleCoreEvents();
    this->_game.process(this->_renderer, this->_window);
    this->_renderer.update();
}

void SW::SemestralWork::clearDisplay() {
    this->_renderer.clearColor();
}

void SW::SemestralWork::handleCoreEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            // User requested application close
            case SDL_QUIT:
                this->_close = true;
                break;
            default:
                break;
        }
    }
}
