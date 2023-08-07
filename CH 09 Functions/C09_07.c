// 7. Write a program that reads characters from the standard input to end-of-file. For each
//    character, have the program report whether it is a letter. If it is a letter, also report
//    its numerical location in the alphabet. For example, c and C would both be letter 3.
//    Incorporate a function that takes a character as an argument and returns the numerical
//    location if the character is a letter and that returns –1 otherwise.

#include<stdio.h>
#include<ctype.h>
#define WIDTH 10

int locate(int ch);
int main(void)
{
    int ch, i;                  // ch for input, i for width control

    printf("Enter characters to get their numerical locations(Ctrl+D to quit):\n");
    printf("('-1' means the character is not a letter.)\n");
    
    while ((ch = getchar()) != EOF)
    {      
        printf("'%c':%2d  ", ch, locate(ch));
        
        i++;                  
        if (i % WIDTH == 0)     // width control
            printf("\n");
    }
    printf("Done.\n");

    return 0;
}

int locate(int ch)              // see letters as numbers and 
{                               // the rest should be easy
    if (isalpha(ch))            // if ch is a letter        
        return tolower(ch) - 'a' + 1;   
    else                        // if ch is not a letter
        return -1;
}