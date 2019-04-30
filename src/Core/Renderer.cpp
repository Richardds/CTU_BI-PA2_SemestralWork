#include "Renderer.h"

SW::Renderer::Renderer() : _renderer(nullptr), last_frame_time(0), time_delta(0) {
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

void SW::Renderer::setRenderingColor(SDL_Color color) const {
    SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
}

void SW::Renderer::prepare() {
    uint32_t current_frame_time = SDL_GetTicks();
    time_delta = (double)(current_frame_time - this->last_frame_time) / 1000;
    this->last_frame_time = SDL_GetTicks();
    this->setRenderingColor(SDL_Color{200, 200, 200, 255});
    SDL_RenderClear(this->_renderer);
}

void SW::Renderer::render(const Entity * entity) const {
    entity->draw(*this);
}

void SW::Renderer::update() const {
    SDL_RenderPresent(this->_renderer);
}

double SW::Renderer::getFrameTime() {
    return this->time_delta;
}

SDL_Renderer * SW::Renderer::getSDLRenderer() const {
    return _renderer;
}
