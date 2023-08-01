// 1. Devise a program that counts the number of characters in its input up to the end of file.

#include<stdio.h>
int main(void)
{
    int ch;         // declare ch as an int type, because char type cannot represent EOF.
    int count = 0;

    printf("Enter some characters:\n");
    while ((ch = getchar()) != EOF)
        count++;
    printf("The text contains %d characters.\n", count);

    return 0;
}
