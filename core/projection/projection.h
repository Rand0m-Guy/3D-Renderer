#ifndef PROJECTION_H
#define PROJECTION_H

#include "../vector/vector2i.h"
#include "../primitives/point/point.h"

class Projection {
    public:
        virtual vec2i_t project(Point) {vec2i_t v; return v;}
};


#endif