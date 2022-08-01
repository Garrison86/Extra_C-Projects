#include <stdio.h>


void passArrayToFunction(char[]); // function prototype


int main(void)
{
    char Ar[] = "abcdefghijklm"; // 13 chars plus '\0'
    // sizeof() returns 14
    printf("Array size before function call = %u\n", sizeof(Ar));
    passArrayToFunction(Ar);
}


void passArrayToFunction(char ar[])
{
    printf("Size of array inside function = %u\n", sizeof(ar));
    // sizeof returns 4 = size of ptr
    printf("Output is: %s\n", ar); // still outputs abcdefghijklm
}
