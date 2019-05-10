#ifndef SEMESTRALWORK_RENDERABLE_H
#define SEMESTRALWORK_RENDERABLE_H

#include "HasPosition.h"
#include "../Core/Renderer.h"

namespace SW {
    /**
     * Entity which can be rendered by SW::Renderer
     */
    class Entity : public HasPosition {
    public:
        /**
         * Constructor
         */
        Entity();
        /**
         * Constructor
         * @param position Entity screen coordinates
         */
        Entity(Position position);
        /**
         * Is called by SW::Renderer on every frame.
         * @param renderer SDL_Renderer wrapper
         */
        virtual void draw(const Renderer & renderer) const = 0;
    };
}

#endif
