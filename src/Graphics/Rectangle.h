#ifndef SEMESTRALWORK_RECTANGLE_H
#define SEMESTRALWORK_RECTANGLE_H

#include "Entity.h"
#include "HasPosition.h"
#include "../Core/Window.h"
#include "../Core/core.h"

namespace SW {
    class Rectangle : public Entity {
    public:
        Rectangle();
        Rectangle(int width, int height, Position position = {0, 0}, SDL_Color _color = {0, 0, 0, 0});
        const SDL_Color & getColor() const;
        void setColor(const SDL_Color & color);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);
        bool overlapsPoint(Position point);
        bool overlapsOtherRectangle(const Rectangle & rectangle);
        bool overlapsHorizontalLine(int offset);
        bool overlapsVerticalLine(int offset);
        void draw(const Renderer & renderer) const override;

    protected:
        int _width;
        int _height;
        SDL_Color _color;
    };
}

#endif
