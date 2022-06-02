#include "Polynomial.h"
#include <cstdio>

Polynomial::Polynomial(double a, double b, double c, double d)
{
    coefficients = new double[4];

    coefficients[0] = a;
    coefficients[1] = b;
    coefficients[2] = c;
    coefficients[3] = d;
}

Polynomial::Polynomial(const Polynomial &ref)
{
    coefficients = new double[4];

    for (int i = 0; i < 4; i++){
        coefficients[i] = ref.coefficients[i];
    }
}

Polynomial::~Polynomial()
{
    if (coefficients)
        delete [] coefficients;
}

Polynomial Polynomial::operator+(const Polynomial &ref)
{
    return Polynomial(coefficients[0] + ref.coefficients[0],
                      coefficients[1] + ref.coefficients[1],
                      coefficients[2] + ref.coefficients[2], 
                      coefficients[3] + ref.coefficients[3]);    
}

Polynomial Polynomial::operator*(const Polynomial &ref)
{
    return Polynomial(coefficients[0] * ref.coefficients[0],
                      coefficients[1] * ref.coefficients[1],
                      coefficients[2] * ref.coefficients[2], 
                      coefficients[3] * ref.coefficients[3]);
}


Polynomial Polynomial::operator=(const Polynomial &ref)
{
    for (int i = 0; i < 4; i++){
        coefficients[i] = ref.coefficients[i];
    }

    return *this;
}

void Polynomial::PrintPolynomial() const
{
    printf("%.2fx^3 + %.2fx^2 + %.2fx + %.2f\n", this->getA(), this->getB(), this->getC(), this->getD());
}