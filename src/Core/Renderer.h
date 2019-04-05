#ifndef SEMESTRALWORK_RENDERER_H
#define SEMESTRALWORK_RENDERER_H

#include "SDL.h"
#include "Window.h"
#include "core.h"

namespace SW {
    class Renderer {
    public:
        Renderer();
        ~Renderer();
        bool initialize(const Window & window);
        void destroy();
        void update();
        void setRenderingColor(Color color) const;
        void clearColor();
        SDL_Renderer * getSDLRenderer() const;

    private:
        SDL_Renderer * _renderer;
    };
}

#endif
