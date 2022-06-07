#ifndef MATRIX2_H
#define MATRIX2_H

#include "TMatrix.hpp"


class Matrix2 : public TMatrix {
public:
    Matrix2() : TMatrix(2) {}
    virtual ~Matrix2() {}

    virtual int Det() const {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
};


#endif