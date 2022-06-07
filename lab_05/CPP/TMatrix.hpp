#ifndef TMATRIX_H
#define TMATRIX_H  

class TMatrix {
protected:
    unsigned int dimension;
    int **matrix;

public:
    TMatrix(unsigned int i_dimension);
    TMatrix();
    virtual ~TMatrix();

    int Sum() const;
    virtual int Det() const = 0;

    void EnterMatrix();
    void PrintMatrix();
};


#endif