#ifndef SEMESTRALWORK_RENDERABLE_H
#define SEMESTRALWORK_RENDERABLE_H

#include "../Core/Renderer.h"

namespace SW {
    class Renderable {
    public:
        virtual void render(const Renderer & renderer) = 0;
    };
}

#endif
