#ifndef SEMESTRALWORK_RENDERABLE_H
#define SEMESTRALWORK_RENDERABLE_H

#include "HasPosition.h"
#include "../Core/Renderer.h"

namespace SW {
    class Entity : public HasPosition {
    public:
        Entity();
        Entity(Position position);
        virtual void draw(const Renderer & renderer) const = 0;
    };
}

#endif
