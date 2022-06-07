#ifndef MATRIX3_H
#define MATRIX3_H

#include "TMatrix.hpp"


class Matrix3 : public TMatrix {
public:
    Matrix3() : TMatrix(3) {}
    virtual ~Matrix3() {}

    virtual int Det() const {
        return + matrix[0][0] * matrix[1][1] * matrix[2][2]
               + matrix[0][1] * matrix[1][2] * matrix[2][0]
               + matrix[1][0] * matrix[2][1] * matrix[0][2]
               - matrix[0][2] * matrix[1][1] * matrix[2][0]
               - matrix[0][1] * matrix[1][0] * matrix[2][2]
               - matrix[1][2] * matrix[2][1] * matrix[0][0];
    }
};


#endif