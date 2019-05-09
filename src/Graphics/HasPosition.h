#ifndef SEMESTRALWORK_HASPOSITION_H
#define SEMESTRALWORK_HASPOSITION_H

#include <SDL2/SDL.h>
#include "../Core/core.h"

namespace SW {
    class Renderer;

    class HasPosition {
    public:
        HasPosition();
        explicit HasPosition(Position position);
        Position getPosition() const;

        virtual void setPosition(Position position);
        int getPositionX() const;

        virtual void setPositionX(int position_x);
        int getPositionY() const;

        virtual void setPositionY(int position_y);

    protected:
        Position _position;
    };
}

#endif
