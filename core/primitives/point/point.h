#ifndef POINT_H
#define POINT_H

#include "../../color/color.h"
#include "../../vector/vector3.h"

class Point {
    private:
        vec3_t position;

    public:
        Point(vec3_t);
        void setPoint(vec3_t);
        float getX();
        float getY();
        float getZ();
        vec3_t getPosition();
};

#endif