#include "TMatrix.hpp"
#include <cstdio>


TMatrix::TMatrix(unsigned int i_dimension)
{
    dimension = i_dimension;
    matrix = new int *[dimension];

    for (unsigned int i = 0; i < dimension; ++i){
        matrix[i] = new int[dimension];
    }
}


TMatrix::TMatrix()
{
    dimension = 0;
    matrix = 0;
}


TMatrix::~TMatrix()
{
    for (unsigned int i = 0; i < dimension; ++i){
        if (matrix[i])
            delete [] matrix[i];
    }

    if (matrix)
        delete [] matrix;
}


void TMatrix::EnterMatrix()
{
    printf("Enter %d-dimension matrix row by row:\n", dimension);

    for (unsigned int i = 0; i < dimension; ++i){
        putchar('\t');
        for (unsigned int j = 0; j < dimension; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    putchar('\n');
}


void TMatrix::PrintMatrix()
{
    for (unsigned int i = 0; i < dimension; ++i){
        putchar('\t');
        for (unsigned int j = 0; j < dimension; ++j){
            printf("%-5d ", matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}


int TMatrix::Sum() const
{
    int result = 0;
     
    for (unsigned int i = 0; i < dimension; ++i){
        for (unsigned int j = 0; j < dimension; ++j){
            result += matrix[i][j];
        }
    }
    return result;
}







