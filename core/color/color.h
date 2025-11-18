#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <string>
#include <vector>
#include "color_models.h"

class Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        Color();
        Color(ColorModel, int v1, int v2, int v3, int alpha = 255);
        Color(std::string);
        std::vector<int> getAsRGBA();
        std::vector<int> getAsHSVA();
        std::vector<int> getAsHSLA();
        std::string getAsHex();
        float getAsFloat_r();
        float getAsFloat_g();
        float getAsFloat_b();
        float getAsFloat_a();
};

#endif