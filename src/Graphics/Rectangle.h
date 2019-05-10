#ifndef SEMESTRALWORK_RECTANGLE_H
#define SEMESTRALWORK_RECTANGLE_H

#include "Entity.h"
#include "HasPosition.h"
#include "../Core/Window.h"
#include "../Core/core.h"

namespace SW {
    /**
     * Rectangle entity
     */
    class Rectangle : public Entity {
    public:
        /**
         * Constructor
         */
        Rectangle();
        /**
         * Constructor
         * @param width Rectangle width
         * @param height Rectangle height
         * @param position Rectangle screen coordinates
         * @param _color Rectangle color
         */
        Rectangle(int width, int height, Position position = {0, 0}, SDL_Color _color = {0, 0, 0, 0});
        /**
         * @return Rectangle color
         */
        const SDL_Color & getColor() const;
        /**
         * Sets rectangle color
         * @param color
         */
        void setColor(const SDL_Color & color);
        /**
         * @return Rectangle width
         */
        int getWidth() const;
        /**
         * Sets rectangle width
         * @param width
         */
        void setWidth(int width);
        /**
         * @return Rectangle height
         */
        int getHeight() const;
        /**
         * Sets rectangle height
         * @param height
         */
        void setHeight(int height);
        /**
         * Checks if rectangle overlaps with given point.
         * @param point Screen coordinates of point
         * @return true if overlaps, otherwise false
         */
        bool overlapsPoint(Position point) const;
        /**
         * Checks if rectangle overlaps with another rectangle.
         * @param rectangle
         * @return true if overlaps, otherwise false
         */
        bool overlapsOtherRectangle(const Rectangle & rectangle) const;
        /**
         * Checks if rectangle overlaps with horizontal line given by y offset starting on top.
         * @param offset Y offset of line
         * @return true if overlaps, otherwise false
         */
        bool overlapsHorizontalLine(int offset) const;
        /**
         * Checks if rectangle overlaps with vertical line given by x offset starting on left.
         * @param offset Y offset of line
         * @return true if overlaps, otherwise false
         */
        bool overlapsVerticalLine(int offset) const;
        /**
         * Draws rectangle to screen.
         * @param renderer SDL_Renderer wrapper
         */
        void draw(const Renderer & renderer) const override;

    protected:
        int _width;
        int _height;
        SDL_Color _color;
    };
}

#endif
