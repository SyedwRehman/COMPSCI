#include <stdio.h>

int main()
{
    const float num1 = 10.5;
    float num2 = 5.2;
    double num3 = 7.8;
    const long double num4 = 3.14;
    long double num5 = 2.71;

    // Addition
    float sumFloat = num1 + num2;
    double sumDouble = num1 + num3;
    long double sumLongDouble = num4 + num5;

    printf("Addition:\n");
    printf("%.2f + %.2f = %.2f\n", num1, num2, sumFloat);
    printf("%.2f + %.2f = %.2f\n", num1, num3, sumDouble);
    printf("%.2Lf + %.2Lf = %.2Lf\n", num4, num5, sumLongDouble);
    printf("\n");

    // Subtraction
    float diffFloat = num1 - num2;
    double diffDouble = num1 - num3;
    long double diffLongDouble = num4 - num5;

    printf("Subtraction:\n");
    printf("%.2f - %.2f = %.2f\n", num1, num2, diffFloat);
    printf("%.2f - %.2f = %.2f\n", num1, num3, diffDouble);
    printf("%.2Lf - %.2Lf = %.2Lf\n", num4, num5, diffLongDouble);
    printf("\n");

    // Multiplication
    float productFloat = num1 * num2;
    double productDouble = num1 * num3;
    long double productLongDouble = num4 * num5;

    printf("Multiplication:\n");
    printf("%.2f * %.2f = %.2f\n", num1, num2, productFloat);
    printf("%.2f * %.2f = %.2f\n", num1, num3, productDouble);
    printf("%.2Lf * %.2Lf = %.2Lf\n", num4, num5, productLongDouble);
    printf("\n");

    // Division
    float quotientFloat = num1 / num2;
    double quotientDouble = num1 / num3;
    long double quotientLongDouble = num4 / num5;

    printf("Division:\n");
    printf("%.2f / %.2f = %.2f\n", num1, num2, quotientFloat);
    printf("%.2f / %.2f = %.2f\n", num1, num3, quotientDouble);
    printf("%.2Lf / %.2Lf = %.2Lf\n", num4, num5, quotientLongDouble);
    printf("\n");

    // Compound Assignment Operators
    num2 += num1; // num2 = num2 +num1
    num3 -= num4; // num3 = num3 - num4
    num5 *= num4; // num5 = num5 * num4
    float P1 = num1; // since I cannot change the value of num1
    P1 /= num2; // P1 = P1/num2

    printf("Compound Assignment Operators:\n");
    printf("num2 += num1: %.2f\n", num2);
    printf("num3 -= num4: %.2f\n", num3);
    printf("num5 *= num4: %.2Lf\n", num5);
    printf("num1 /= num2: %.2f\n", P1);
}