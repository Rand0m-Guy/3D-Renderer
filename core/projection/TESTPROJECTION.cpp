#include "TESTPROJECTION.h"

vec2i_t Test::project(vec3_t point) {
    vec2i_t f;
    f.x = (int)point.x;
    f.y = (int)point.y;
    return f;
}