#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "../vector/vector2i.h"
#include "../primitives/point/point.h"

class Perspective {
    public:
        vec2i_t project(Point);
};


#endif