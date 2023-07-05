#include <stdio.h>

int main()
{
    int x =19 ;
    int y = x + 5; // Using uninitialized variable x
    printf("%d\n", y);
}
