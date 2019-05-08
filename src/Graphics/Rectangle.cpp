#include "Rectangle.h"
#include "../Core/Renderer.h"

SW::Rectangle::Rectangle() : Entity(), _width(100), _height(100), _color() {
    //
}

SW::Rectangle::Rectangle(int width, int height, Position position, SDL_Color color)
    : Entity(position),
      _width(width),
      _height(height),
      _color(color) {
    //
}

const SDL_Color & SW::Rectangle::getColor() const {
    return _color;
}

void SW::Rectangle::setColor(const SDL_Color & color) {
    Rectangle::_color = color;
}

int SW::Rectangle::getWidth() const {
    return this->_width;
}

void SW::Rectangle::setWidth(int width) {
    this->_width = width;
}

int SW::Rectangle::getHeight() const {
    return this->_height;
}

void SW::Rectangle::setHeight(int height) {
    this->_height = height;
}

bool SW::Rectangle::overlapsPoint(Position point) {
    int left = this->getPositionX();
    int right = left + this->getWidth();
    int top = this->getPositionY();
    int bottom = top + this->getHeight();

    return left <= point.x && point.x <= right && top <= point.y && point.y <= bottom;
}

bool SW::Rectangle::overlapsOtherRectangle(const SW::Rectangle & rectangle) {
    int left = this->getPositionX();
    int right = left + this->getWidth();
    int top = this->getPositionY();
    int bottom = top + this->getHeight();

    int rhs_left = rectangle.getPositionX();
    int rhs_right = rhs_left + rectangle.getWidth();
    int rhs_top = rectangle.getPositionY();
    int rhs_bottom = rhs_top + rectangle.getHeight();

    bool fuck = rhs_right >= left && rhs_left <= right && rhs_top <= bottom && rhs_bottom >= top;
    return fuck;
}

bool SW::Rectangle::overlapsHorizontalLine(int offset) {
    int top = this->getPositionY();
    int bottom = top + this->getHeight();
    return top <= offset && offset <= bottom;
}

bool SW::Rectangle::overlapsVerticalLine(int offset) {
    int left = this->getPositionX();
    int right = left + this->getWidth();
    return left <= offset && offset <= right;
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
