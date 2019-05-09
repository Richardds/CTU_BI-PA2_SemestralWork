#ifndef SEMESTRALWORK_RENDERER_H
#define SEMESTRALWORK_RENDERER_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "core.h"
#include "../Graphics/Entity.h"

namespace SW {
    class Entity;

    class Renderer {
    public:
        Renderer();
        ~Renderer();
        bool initialize(const Window & window);
        void destroy();
        void render(const Entity * entity) const;
        void update() const;
        void setRenderingColor(SDL_Color color) const;
        void prepare();
        double getFrameTime();
        SDL_Renderer * getSDLRenderer() const;

        static const int FPS = 60;

    private:
        SDL_Renderer * _renderer;
        uint32_t last_frame_time;
        double time_delta;
    };
}

#endif
