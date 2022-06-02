#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cmath>

//ax^3 + bx^2 + cx + d - polynomial

class Polynomial {
    double *coefficients;
public:
    Polynomial(double a = 0, double b = 0, double c = 0, double d = 0);
    Polynomial(const Polynomial &ref);
    ~Polynomial();

    double getA() const { return coefficients[0]; }
    double getB() const { return coefficients[1]; }
    double getC() const { return coefficients[2]; }
    double getD() const { return coefficients[3]; }

    double getValueInPoint(double x) const
        { return coefficients[0] * pow(x, 3) + coefficients[1] * pow(x, 2) + coefficients[2] * x + coefficients[3]; }

    Polynomial operator+(const Polynomial &ref);
    Polynomial operator*(const Polynomial &ref);
    Polynomial operator=(const Polynomial &ref);
        
    void PrintPolynomial() const;
};




#endif