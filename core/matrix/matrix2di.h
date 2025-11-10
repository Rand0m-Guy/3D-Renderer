#ifndef MATRIX2DI_H
#define MATRIX2DI_H

#include <vector>

class Matrix2Di {
    private:
        int width;
        int height;
        std::vector<std::vector<int>> matrix;

    public:
        Matrix2Di(int w, int h);
};

#endif