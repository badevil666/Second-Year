#include "stack.h"
#include <stdio.h>

int main()
{
    char string[50];
    int len, i;
    printf("Enter the string : ");
    scanf(" %[^\n]", string);
    for(len = 0; string[len] != '\0'; len++);
    for(i = 0; i < len/2; i++)
        push(string[i]);
    for(i =( len % 2 ? len / 2 + 1: len / 2 ); i < len; i++)
        if(pop() != string[i])
        {
            printf("The string is not palindrome.\n");
            return 0;
        }
    printf("The string is palindrome.\n");
    return 0;
}