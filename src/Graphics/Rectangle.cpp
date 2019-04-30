#include "Rectangle.h"
#include "../Core/Renderer.h"

SW::Rectangle::Rectangle() : Entity(), _width(100), _height(100), _color() {
    //
}

SW::Rectangle::Rectangle(int width, int height, SDL_Point position, SDL_Color color)
    : Entity(position),
      _width(width),
      _height(height),
      _color(color) {
    //
}

void SW::Rectangle::draw(const SW::Renderer & renderer) const {
    SDL_Rect rect;
    rect.w = this->_width;
    rect.h = this->_height;
    rect.x = this->_position.x;
    rect.y = this->_position.y;
    renderer.setRenderingColor(this->_color);
    SDL_RenderFillRect(renderer.getSDLRenderer(), &rect);
}

const SDL_Color & SW::Rectangle::getColor() const {
    return _color;
}

void SW::Rectangle::setColor(const SDL_Color & color) {
    Rectangle::_color = color;
}
