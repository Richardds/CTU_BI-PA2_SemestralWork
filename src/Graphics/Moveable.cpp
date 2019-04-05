#include "Moveable.h"

SW::Moveable::Moveable()
        : _width(100),
          _height(100),
          _offset_x(0),
          _offset_y(0) {
    //
}

SW::Moveable::Moveable(int width, int height, int offset_x, int offset_y)
        : _width(width),
          _height(height),
          _offset_x(offset_x),
          _offset_y(offset_y) {
    //
}

void SW::Moveable::moveToWindowCenter(const SW::Window & window) {
    this->_offset_x = (window.getWidth() / 2) - (this->_width / 2);
    this->_offset_y = (window.getHeight() / 2) - (this->_height / 2);
}

int SW::Moveable::getWidth() const {
    return _width;
}

void SW::Moveable::setWidth(int width) {
    Moveable::_width = width;
}

int SW::Moveable::getHeight() const {
    return _height;
}

void SW::Moveable::setHeight(int height) {
    Moveable::_height = height;
}

int SW::Moveable::getOffsetX() const {
    return _offset_x;
}

void SW::Moveable::setOffsetX(int offsetX) {
    _offset_x = offsetX;
}

int SW::Moveable::getOffsetY() const {
    return _offset_y;
}

void SW::Moveable::setOffsetY(int offsetY) {
    _offset_y = offsetY;
}
