#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <vector>

class Matrix2D {
    private:
        int width;
        int height;
        std::vector<std::vector<float>> matrix;

    public:
        Matrix2D(int w, int h);
};

#endif