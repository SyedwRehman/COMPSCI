#include <stdio.h>
int main()
{
    int a = 5;
    int b = 10;
    if (a == b)
    {
        printf("a is equal to b\n");
    }
    else if (a != b)
    {
        printf("a is not equal to b\n");
    }
    else if (a < b)
    {
        printf("a is less than b\n");
    }
    else if (a > b)
    {
        printf("a is greater than b\n");
    }
    else if (a <= b)
    {
        printf("a is less than or equal to b\n");
    }
    else if (a >= b)
    {
        printf("a is greater than or equal to b\n");
    }
    else
    {
        printf(" None of the conditions are true \n");
    }
    int A = 1;
    int B = 0;
    if (!A)
    {
        printf("A is false \n");
    }
    if (A || B)
    {
        printf("At least one of A or B is true \n");
    }
    if (A && B)
    {
        printf(" Both A and B are true \n");
    }
}
