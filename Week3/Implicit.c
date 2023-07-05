#include <stdio.h>
int main()
{
    int num = 10;
    double result = num / 3; // Implicitly convert int to double
    printf(" Result : %f\n", result);
    int num2 = 10.6;
    printf(" num2 : %d\n", num2); // Implicitly convert double to int
}
