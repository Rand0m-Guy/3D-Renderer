#include "matrix2d.h"

Matrix2D::Matrix2D(int w, int h) : width(w), height(h) {
    matrix.resize(h);
    for(int i = 0; i < h; i++) {
        matrix[i].resize(w);
    }
}