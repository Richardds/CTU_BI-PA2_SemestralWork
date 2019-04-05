#include "Window.h"

SW::Window::Window(int width, int height, const std::string & title) : _window(nullptr), _width(width), _height(height) {
    this->_title = title;
}

SW::Window::~Window() {
    this->destroy();
}

bool SW::Window::initialize() {
    this->_window = SDL_CreateWindow(
            this->_title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            this->_width,
            this->_height,
            0
    );
    return this->_window != nullptr;
}

void SW::Window::destroy() {
    if (this->_window != nullptr) {
        SDL_DestroyWindow(this->_window);
    }
    this->_window = nullptr;
}

const std::string & SW::Window::getTitle() const {
    return _title;
}

void SW::Window::setTitle(const std::string & title) {
    this->_title = title;
}

int SW::Window::getWidth() const {
    return _width;
}

void SW::Window::setWidth(int width) {
    this->_width = width;
}

int SW::Window::getHeight() const {
    return _height;
}

void SW::Window::setHeight(int height) {
    this->_height = height;
}

SDL_Window * SW::Window::getSDLWindow() const {
    return _window;
}
