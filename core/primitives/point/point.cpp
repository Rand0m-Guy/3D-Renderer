#include "point.h"

Point::Point(vec3_t pos) : position(pos) {}

float Point::getX() {
    return position.x;
}

float Point::getY() {
    return position.y;
}

float Point::getZ() {
    return position.z;
}

vec3_t Point::getPosition() {
    return position;
}
