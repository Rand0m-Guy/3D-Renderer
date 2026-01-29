#include "perspective.h"

vec2i_t Perspective::project(Point p) {
    float focalLength = 1;
    vec2i_t projectedPoint = {
        .x = (int)((focalLength * p.getX()) / p.getZ()),
        .y = (int)((focalLength * p.getY()) / p.getZ())
    };

    return projectedPoint;
}