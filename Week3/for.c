#include <stdio.h>

int main()
{
    int rows = 5;
    int columns = 3;

    for (int i = 1; i <= rows; i++) // i =1:5
    {
        for (int j = 1; j <= columns; j++) // j = 1:3
        {
            printf("(%d, %d) ", i, j);
        }
        printf("\n");
    }
}


