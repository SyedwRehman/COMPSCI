#include <stdio.h>

int main()
{
    const int num1 = 10;
    const int num2 = 3;

    // 1. Print the division using int placeholder, ignoring anything after the decimal
    int resultInt = num1 / num2;
    printf("Division without casting using int placeholder: %d\n", resultInt);

    // 2. Print the division using double placeholder without casting (warning expected)
    int resultDoubleNoCast = num1 / num2;
    printf("Division without casting floating-point placeholder %f\n", resultDoubleNoCast);

    // 3. Print the division by casting one of the operands
    //double sy = num1 / (double)num2
    printf("Division (double with cast): %f\n", num1 / (double)num2);

    // 4. Print the division by casting both operands
    double resultDoubleBothCasted = (double)num1 / (double)num2;
    printf("Division (double with both cast): %f\n", resultDoubleBothCasted);
}