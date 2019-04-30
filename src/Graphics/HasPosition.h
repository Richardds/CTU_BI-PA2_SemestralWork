#ifndef SEMESTRALWORK_HASPOSITION_H
#define SEMESTRALWORK_HASPOSITION_H

#include "SDL.h"

namespace SW {
    class Renderer;

    class HasPosition {
    public:
        HasPosition();
        explicit HasPosition(SDL_Point position);
        SDL_Point getPosition() const;
        void setPosition(SDL_Point position);
        int getPositionX() const;
        void setPositionX(int position_x);
        int getPositionY() const;
        void setPositionY(int position_y);

    protected:
        SDL_Point _position;
    };
}

#endif
