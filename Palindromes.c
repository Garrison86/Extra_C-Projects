#include <stdio.h>
#include <string.h>


int isPalindrome(char[]);


int main(void)
{
    while(1){
    char str[80] = {'\0'};
    printf("Enter a string to test if it is a palindrome: ");
    gets(str);
    printf("%s%s%s%s", "The string ", str,
           isPalindrome(str) ? " is" : " is not", " a palindrome\n");
    }
}


int isPalindrome(char *p)
{
    unsigned int len = strlen(p), ctr = 0, palindrome;
    char *start = p;         // save start of the array
    p += len - 1;            // p now points to last char
    while (++ctr <= len / 2) // loop until midstring
        if (!(palindrome = (*start++ == *p--)))
            break; // if different
    return (palindrome);
}
