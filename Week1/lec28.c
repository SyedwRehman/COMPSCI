#include <stdio.h>

int main()
{

    // -------------------------- char --------------------------
    char Ped_RealChar = 'P';
    // char range: -128 to 127
    char Ped_NumChar = 80;
    // unsigned char range: 0 to 255
    unsigned char Ped_NumChar_unsigned = 252;
    // ------------------------- short --------------------------
    // short range: -32768 to 32767
    short Ped_sh = -1234;
    // unsigned short range: 0 to 65535
    unsigned short Ped_sh_unsigned = 56789;
    //--------------------------- int ---------------------------
    // int range: -2147483648 to 2147483647
    int Ped_int = -42;
    // unsigned int range: 0 to 4294967295
    unsigned int Ped_int_unsigned = 123456;
    // -------------------------- long --------------------------
    // long range: -9223372036854775808 to 9223372036854775807
    long Ped_long = -9876543210;
    // unsigned long range: 0 to 18446744073709551615
    unsigned long Ped_long_unsigned = 9876543210;
    // #----------------------- long long -----------------------
    // long long range: -9223372036854775808 to 9223372036854775807
    long long Ped_longlong = -123456789012345;
    // unsigned long long range: 0 to 18446744073709551615
    unsigned long long Ped_longlong_unsigned = 123456789012345;

    // ------------------------ printing ------------------------
    printf("char used for saving character: %c\n", Ped_RealChar);
    printf("char used saving integer BUT the character is printed: %c\n", Ped_NumChar);
    printf("char used saving integer: %d\n", Ped_NumChar);
    printf("unsigned char saving integer: %u\n", Ped_NumChar_unsigned);
    printf("short: %hd\n", Ped_sh);
    printf("unsigned short: %hu\n", Ped_sh_unsigned);
    printf("int: %d\n", Ped_int);
    printf("unsigned int: %u\n", Ped_int_unsigned);
    printf("long: %ld\n", Ped_long);
    printf("unsigned long: %lu\n", Ped_long_unsigned);
    printf("long long: %lld\n", Ped_longlong);
    printf("unsigned long long: %llu\n", Ped_longlong_unsigned);
}