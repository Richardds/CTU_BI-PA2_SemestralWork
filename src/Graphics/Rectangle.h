#ifndef SEMESTRALWORK_RECTANGLE_H
#define SEMESTRALWORK_RECTANGLE_H

#include "Renderable.h"
#include "Moveable.h"
#include "../Core/Window.h"
#include "../Core/core.h"

namespace SW {
    class Rectangle : public Renderable, public Moveable {
    public:
        Rectangle();
        Rectangle(int width, int height, int offset_x = 0, int offset_y = 0);
        void render(const Renderer & renderer) override;
        const Color & getColor() const;
        void setColor(const Color & color);

    private:
        Color _color;
    };
}


#endif
