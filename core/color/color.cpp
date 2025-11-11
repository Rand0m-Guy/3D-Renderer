#include "color.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

Color::Color(ColorModel cm, int v1, int v2, int v3, int alpha) {
    if(cm == RGB) {
        this->r = (uint8_t)std::clamp(v1, 0, 255);
        this->g = (uint8_t)std::clamp(v2, 0, 255);
        this->b = (uint8_t)std::clamp(v3, 0, 255);
        this->a = (uint8_t)std::clamp(alpha, 0, 255);
        return;
    }
    
    float C, m, rP, gP, bP;

    float s = (float)std::clamp(v2, 0, 100) / 100.0f;
    float lastValue = (float)std::clamp(v3, 0, 100) / 100.0f;
    
    if(cm == HSV) { // HSV to RGB conversion
        C = s * lastValue;
        m = lastValue - C;
    } else if(cm == HSL) {
        C = (1 - fabs(2 * lastValue - 1)) * s;
        m = lastValue - C/2;
    }

    float X = C * (float)(1 - fabs((v1 / 60) % 2 - 1));
    
    if(v1 >= 0 && v1 < 60) {
        rP = C; gP = X; bP = 0;
    } else if(v1 >= 60 && v1 < 120) {
        rP = X; gP = C; bP = 0;
    } else if(v1 >= 120 && v1 < 180) {
        rP = 0; gP = C; bP = X;
    } else if(v1 >= 180 && v1 < 240) {
        rP = 0; gP = X; bP = C;
    } else if(v1 >= 240 && v1 < 300) {
        rP = X; gP = 0; bP = C;
    } else {
        rP = C; gP = 0; bP = X;
    }

    this->r = (uint8_t)((rP + m) * 255);
    this->g = (uint8_t)((gP + m) * 255);
    this->b = (uint8_t)((bP + m) * 255);
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

std::vector<int> Color::getAsRGBA() {
    return {this->r, this->g, this->b, this->a};
}

// std::vector<int> Color::getAsHSVA() {}

// std::vector<int> Color::getAsHSLA() {}

std::string Color::getAsHex() {
    std::string hexColor = "#00000000";
    hexColor[1] = (this->r / 16 >= 10) ? (this->r / 16) - 10 + 'A' : (this->r / 16) + '0';
    hexColor[2] = (this->r % 16 >= 10) ? (this->r % 16) - 10 + 'A' : (this->r % 16) + '0';
    hexColor[3] = (this->g / 16 >= 10) ? (this->g / 16) - 10 + 'A' : (this->g / 16) + '0';
    hexColor[4] = (this->g % 16 >= 10) ? (this->g % 16) - 10 + 'A' : (this->g % 16) + '0';
    hexColor[5] = (this->b / 16 >= 10) ? (this->b / 16) - 10 + 'A' : (this->b / 16) + '0';
    hexColor[6] = (this->b % 16 >= 10) ? (this->b % 16) - 10 + 'A' : (this->b % 16) + '0';
    hexColor[7] = (this->a / 16 >= 10) ? (this->a / 16) - 10 + 'A' : (this->a / 16) + '0';
    hexColor[8] = (this->a % 16 >= 10) ? (this->a % 16) - 10 + 'A' : (this->a % 16) + '0';

    return hexColor;
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