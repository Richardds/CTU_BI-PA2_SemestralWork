#ifndef SEMESTRALWORK_MOVEABLE_H
#define SEMESTRALWORK_MOVEABLE_H

#include "../Core/Window.h"

namespace SW {
    class Moveable {
    public:
        Moveable();
        Moveable(int width, int height, int offset_x = 0, int offset_y = 0);
        void moveToWindowCenter(const Window & window);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);
        int getOffsetX() const;
        void setOffsetX(int offsetX);
        int getOffsetY() const;
        void setOffsetY(int offsetY);

    protected:
        int _width;
        int _height;
        int _offset_x;
        int _offset_y;
    };
}

#endif
