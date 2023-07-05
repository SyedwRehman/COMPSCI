#include <stdio.h>
// Compile and run the code with and without string.h
#include <string.h>

int main()
{
    char c = 'P';
    char s[] = "Pedram";
    char s2[] = "Pasandide";

    printf("Character: %c\n", c);
    printf("String: %s\n", s);
    printf("s[0]: %c\n", s[0]);
    printf("s[5]: %c\n", s[5]);
    printf("Size of s: %zu\n", sizeof(s));
    printf("s[6] (null character): %d\n", s[6]);

    char s3[20]; // Make sure s3 has enough space to hold the concatenated string

    strcpy(s3, s);  // Copy the content of s to s3
    strcat(s3, s2); // Concatenate s2 to s3

    printf("s3: %s\n", s3);

    return 0;
}