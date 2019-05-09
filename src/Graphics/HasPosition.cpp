#include "HasPosition.h"

SW::HasPosition::HasPosition() : _position({0, 0}) {}

SW::HasPosition::HasPosition(SW::Position position) : _position(position) {}

SW::Position SW::HasPosition::getPosition() const {
    return this->_position;
}

void SW::HasPosition::setPosition(SW::Position position) {
    this->_position = position;
}

int SW::HasPosition::getPositionX() const {
    return this->_position.x;
}

void SW::HasPosition::setPositionX(int position_x) {
    this->_position.x = position_x;
}

int SW::HasPosition::getPositionY() const {
    return this->_position.y;
}

void SW::HasPosition::setPositionY(int position_y) {
    this->_position.y = position_y;
}
