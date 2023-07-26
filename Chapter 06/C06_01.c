// 1. Write a program that creates an array with 26 elements
//    and stores the 26 lowercase letters in it. Also have it show the array contents.
   /* pe6-1.c */
   /* this implementation assumes the character codes */
   /* are sequential, as they are in ASCII. */

#include <stdio.h>
#define SIZE 26
int main( void )
{
    char lcase[SIZE];
    int i;
    
    for (i = 0; i < SIZE; i++)
        lcase[i] = 'a' + i;
    for (i = 0; i < SIZE; i++)
        printf("%c", lcase[i]);
    printf("\n");
    return 0;
}