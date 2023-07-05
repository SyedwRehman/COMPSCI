#include <stdio.h>

int main()
{
    const float F = 1.23456789f;
    const double D = 1.23456789;
    const long double L = 1.23456789L;

    printf("Original values:\n");
    printf("Float: %.8f\n", F);
    printf("Double: %.8lf\n", D);
    printf("Long Double: %.8Lf\n\n", L);

    printf("Rounded values:\n");
    printf("Float: %.20f\n", F);
    printf("Double: %.20lf\n", D);
    printf("Long Double: %.20Lf\n", L);
}