#include "Moveable.h"

SW::Moveable::Moveable()
        : _position_x(0),
          _position_y(0) {
    //
}

SW::Moveable::Moveable(int width, int height, int offset_x, int offset_y)
        : _position_x(offset_x),
          _position_y(offset_y) {
    //
}

void SW::Moveable::moveToWindowCenter(const SW::Window & window) {
    this->_position_x = (window.getWidth() / 2) - (this->_width / 2);
    this->_position_y = (window.getHeight() / 2) - (this->_height / 2);
}

int SW::Moveable::getPositionX() const {
    return _position_x;
}

void SW::Moveable::setPositionX(int position_x) {
    _position_x = position_x;
}

int SW::Moveable::getPositionY() const {
    return _position_y;
}

void SW::Moveable::setPositionY(int position_y) {
    _position_y = position_y;
}
