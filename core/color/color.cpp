#include "color.h"
#include <algorithm>
#include <iostream>
#include <string>

Color::Color(int v1, int v2, int v3, int alpha) {
    this->r = (uint8_t)std::clamp(v1, 0, 255);
    this->g = (uint8_t)std::clamp(v2, 0, 255);
    this->b = (uint8_t)std::clamp(v3, 0, 255);
    this->a = (uint8_t)std::clamp(alpha, 0, 255);
}

Color::Color(std::string hex) {
    if(hex.length() != 7 && hex.length() != 9) {
        std::cout<<hex.length()<<std::endl;
        std::cerr<<"Improper hex code format (Improper Length)"<<std::endl;
    }
    if(hex[0] != '#') {
        std::cerr<<"Improper hex code format (No #)"<<std::endl;
    }
    for(int i = 1; i < (int)hex.length(); i++) {
        if(!(48 <= hex[i] <= 57 || 65 <= hex[i] <= 70)) { // Not in 0-9, A-F
            std::cerr<<"Improper hex code format (Improper Values)"<<std::endl;
        }
    }

    if(hex.length() == 7) this->a = 255;

    int rL = (hex[2] - '0' > 9) ? hex[2] - 'A' + 10 : hex[2] - '0';
    this->r = (uint8_t)(rL + 16 * ((hex[1] - '0' > 9) ? hex[1] - 'A' + 10 : hex[1] - '0'));
    int gL = (hex[4] - '0' > 9) ? hex[4] - 'A' + 10 : hex[4] - '0';
    this->g = (uint8_t)(gL + 16 * ((hex[3] - '0' > 9) ? hex[3] - 'A' + 10 : hex[3] - '0'));
    int bL = (hex[6] - '0' > 9) ? hex[6] - 'A' + 10 : hex[6] - '0';
    this->b = (uint8_t)(bL + 16 * ((hex[5] - '0' > 9) ? hex[5] - 'A' + 10 : hex[5] - '0'));

    if(hex.length() == 9) {
        int aL = (hex[8] - '0' > 9) ? hex[8] - 'A' + 10 : hex[8] - '0';
        this->a = (uint8_t)(rL + 16 * ((hex[7] - '0' > 9) ? hex[7] - 'A' + 10 : hex[7] - '0'));
    }
}

float Color::getAsFloat_r() {
    return (float) r / 255.0f;
}

float Color::getAsFloat_g() {
    return (float) g / 255.0f;
}

float Color::getAsFloat_b() {
    return (float) b / 255.0f;
}

float Color::getAsFloat_a() {
    return (float) a / 255.0f;
}