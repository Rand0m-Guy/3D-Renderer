#ifndef MATRIX2DI_H
#define MATRIX2DI_H

#include <vector>

class Matrix2Di {
    private:
        std::vector<std::vector<int>> matrix;

    public:
        int width;
        int height;
        Matrix2Di(int w, int h);
};

#endif