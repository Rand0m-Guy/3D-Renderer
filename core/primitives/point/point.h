#ifndef POINT_H
#define POINT_H

#include "../../color/color.h"
#include "../../vector/vector3.h"

class Point {
    private:
        vec3_t position;
        Color color;
        int size;

    public:
        Point(vec3_t, Color, int);
};

#endif