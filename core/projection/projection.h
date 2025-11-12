#ifndef PROJECTION_H
#define PROJECTION_H

#include "../vector/vector2i.h"
#include "../vector/vector3.h"

class Projection {
    public:
        virtual vec2i_t project(vec3_t) {vec2i_t v; return v;}
};


#endif