#include "matrix2di.h"

Matrix2Di::Matrix2Di(int w, int h) : width(w), height(h) {
    matrix.resize(h);
    for(int i = 0; i < h; i++) {
        matrix[i].resize(w);
    }
}