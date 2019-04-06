#ifndef SEMESTRALWORK_MOVEABLE_H
#define SEMESTRALWORK_MOVEABLE_H

#include "../Core/Window.h"

namespace SW {
    class Moveable {
    public:
        Moveable();
        Moveable(int width, int height, int offset_x = 0, int offset_y = 0);
        void moveToWindowCenter(const Window & window);
        int getPositionX() const;
        void setPositionX(int position_x);
        int getPositionY() const;
        void setPositionY(int position_y);

    protected:
        int _position_x;
        int _position_y;
    };
}

#endif
