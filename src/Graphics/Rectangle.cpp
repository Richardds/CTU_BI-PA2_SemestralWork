#include "Rectangle.h"

SW::Rectangle::Rectangle() : _color() {
    //
}

SW::Rectangle::Rectangle(int width, int height, int offset_x, int offset_y) : _color(width, height, offset_x, offset_y) {
    //
}

void SW::Rectangle::render(const SW::Renderer & renderer) {
    SDL_Rect rect;
    rect.w = this->_width;
    rect.h = this->_height;
    rect.x = this->_offset_x;
    rect.y = this->_offset_y;
    renderer.setRenderingColor(this->_color);
    SDL_RenderFillRect(renderer.getSDLRenderer(), &rect);
}

const SW::Color & SW::Rectangle::getColor() const {
    return _color;
}

void SW::Rectangle::setColor(const SW::Color & color) {
    Rectangle::_color = color;
}
