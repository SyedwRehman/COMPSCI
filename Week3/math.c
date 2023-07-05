#include <stdio.h>
#include <math.h>

int main()
{
    const double num1 = 4.0;
    const double num2 = 2.5;

    double sqrtResult = sqrt(num1);
    double powResult = pow(num1, num2);
    double sinResult = sin(num1);
    double logResult = log(num1);
    double ceilResult = ceil(num2);
    double fmodResult = fmod(num1, num2);

    printf("Square root of %.2f: %.2f\n", num1, sqrtResult);
    printf("%.2f raised to the power of %.2f: %.2f\n", num1, num2, powResult);
    printf("Sine of %.2f: %.2f\n", num1, sinResult);
    printf("Natural logarithm of %.2f: %.2f\n", num1, logResult);
    printf("Ceiling value of %.2f: %.2f\n", num2, ceilResult);
    printf("Remainder of %.2f divided by %.2f: %.2f\n", num1, num2, fmodResult);
}