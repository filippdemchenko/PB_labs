#include "Matrix2.hpp"
#include "Matrix3.hpp"
#include <cstdio>


int main(int argc, char **argv)
{
    Matrix3 A;
    Matrix2 B;

    A.EnterMatrix();
    B.EnterMatrix();

    printf("sum(A) = %d\n", A.Sum());
    printf("det(A) = %d\n", A.Det());
    printf("det(B) = %d\n", B.Det());

    printf("sum(A) + det(A) + det(B) = %d\n", A.Sum() + A.Det() + B.Det());

    return 0;
}