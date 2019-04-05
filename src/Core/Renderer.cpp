#include "Renderer.h"

SW::Renderer::Renderer() : _renderer(nullptr) {
    //
}

SW::Renderer::~Renderer() {
    this->destroy();
}

bool SW::Renderer::initialize(const Window & window) {
    this->_renderer = SDL_CreateRenderer(window.getSDLWindow(), -1, SDL_RENDERER_PRESENTVSYNC);
    return this->_renderer != nullptr;
}

void SW::Renderer::destroy() {
    if (this->_renderer != nullptr) {
        SDL_DestroyRenderer(this->_renderer);
    }
    this->_renderer = nullptr;
}

void SW::Renderer::setRenderingColor(SW::Color color) const {
    SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
}

void SW::Renderer::clearColor() {
    this->setRenderingColor(Color(200, 200, 200));
    SDL_RenderClear(this->_renderer);
}

void SW::Renderer::update() {
    SDL_RenderPresent(this->_renderer);
}

SDL_Renderer * SW::Renderer::getSDLRenderer() const {
    return _renderer;
}
