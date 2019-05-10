#ifndef SEMESTRALWORK_HASPOSITION_H
#define SEMESTRALWORK_HASPOSITION_H

#include <SDL2/SDL.h>
#include "../Core/core.h"

namespace SW {
    class Renderer;

    /**
     * Holds object screen coordinates.
     */
    class HasPosition {
    public:
        /**
         * Constructor
         */
        HasPosition();
        /**
         * Constructor
         * @param position Screen coordinates
         */
        explicit HasPosition(Position position);
        /**
         * @return Object screen coordinates
         */
        Position getPosition() const;
        /**
         * Sets object position.
         * @param position Screen coordinates
         */
        void setPosition(Position position);
        /**
         * @return Object screen coordinate x
         */
        int getPositionX() const;
        /**
         * Sets object x screen coordinate.
         * @param position_x Screen x coordinate
         */
        void setPositionX(int position_x);
        /**
         * @return Object screen coordinate y
         */
        int getPositionY() const;
        /**
         * Sets object y screen coordinate.
         * @param position_y Screen y coordinate
         */
        void setPositionY(int position_y);

    protected:
        Position _position;
    };
}

#endif
