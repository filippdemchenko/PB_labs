#include "Polynomial.h"
#include <cstdio>



int main()
{
    double a, b, c, d;
    double x;

    // Introduction
    printf("Polynomial has 4 coefficients:\n");
    printf("\tax^3 + bx^2 + cx + d\n\n");

    // Create first P1
    printf("Enter a for P1: "); scanf("%lf", &a);
    printf("Enter b for P1: "); scanf("%lf", &b);
    printf("Enter c for P1: "); scanf("%lf", &c);
    printf("Enter d for P1: "); scanf("%lf", &d);
    putchar('\n');

    Polynomial P1 = Polynomial(a, b, c, d);

    // Create P2
    printf("Enter a for P2: "); scanf("%lf", &a);
    printf("Enter b for P2: "); scanf("%lf", &b);
    printf("Enter c for P2: "); scanf("%lf", &c);
    putchar('\n');

    Polynomial P2 = Polynomial(a, b, c);

    // Create P3
    printf("Enter a for P3: "); scanf("%lf", &a);
    printf("Enter b for P3: "); scanf("%lf", &b);
    putchar('\n');

    Polynomial P3 = Polynomial(a, b);

    // Create P4
    Polynomial P4 = P1 + P2;
    Polynomial P5 = P2 * P3;

    printf("P4 = P1 + P2\n");
    printf("P4: "); P4.PrintPolynomial();
    putchar('\n');

    printf("P5 = P2 * P3\n");
    printf("P5: "); P5.PrintPolynomial();
    putchar('\n');

    printf("Enter some point on the x-axis: "); scanf("%lf", &x);
    putchar('\n');
    
    printf("Value P4 in point %.2f: %.2f\n\n", x, P4.getValueInPoint(x));
    printf("Value P5 in point %.2f: %.2f\n\n", x, P5.getValueInPoint(x));




    return 0;
}