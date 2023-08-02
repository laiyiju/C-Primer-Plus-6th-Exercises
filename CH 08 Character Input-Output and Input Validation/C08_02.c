// 2. Write a program that reads input as a stream of characters until encountering EOF. Have
//    the program print each input character and its ASCII decimal value. Note that characters
//    preceding the space character in the ASCII sequence are nonprinting characters.
//    Treat them specially. If the nonprinting character is a newline or tab, print \n or \t,
//    respectively. Otherwise, use control-character notation. For instance, ASCII 1 is Ctrl+A,
//    which can be displayed as ^A. Note that the ASCII value for A is the value for Ctrl+A
//    plus 64. A similar relation holds for the other nonprinting characters. Print 10 pairs per
//    line, except start a fresh line each time a newline character is encountered. (Note: The
//    operating system may have special interpretations for some control characters and keep
//    them from reaching the program.)

#include<stdio.h>
int main(void)
{
    char ch; 
    int i = 0;
    const int PPL = 10;        // pairs per line

    printf("Enter some characters: \n");
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n'){
            printf("'\\n':%-3d  ", ch);
            printf("\nEnter some new characters or press Ctrl+D to exit:\n");  // input prompt
        }     
        else if (ch == '\t')
            printf("'\\t':%-3d  ", ch);
        else if (ch >= ' ')                    // ASCII printable characters(including SPACE)
            printf("'%c':%-3d  ", ch, ch);      // Notice: 2 specifiers require 2 variables
        else                                  // ASCII control(unprintable) characters
            printf("'^%c':%-3d  ", ch + 64, ch);

        i++;              
        if (i % PPL == 0)                     // 10 pairs per line
            printf("\n");
    }

    return 0;
}