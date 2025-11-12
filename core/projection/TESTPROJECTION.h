#ifndef TEST_H
#define TEST_H

#include "../vector/vector2i.h"
#include "../vector/vector3.h"
#include "projection.h"

class Test: virtual public Projection{
public:
    vec2i_t project(vec3_t);
};

#endif