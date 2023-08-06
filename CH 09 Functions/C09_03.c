// 3. Write a function that takes three arguments: a character and two integers. The character
//    is to be printed. The first integer specifies the number of times that the character is to
//    be printed on a line, and the second integer specifies the number of lines that are to be
//    printed. Write a program that makes use of this function.

#include<stdio.h>

void chrocol(char, int, int);   // character-row-column
int main(void)
{
    char ch;
    int col, row;

    printf("Enter a printable character:\n");      // read character
    while ((ch = getchar()) <= 32)     // if the input is ASCII unprintable characters
        printf("Your input is not printable. Please re-enter:\n");
    
    printf("Enter the numbers of columns and rows:\n"); 
    while ((scanf("%d %d", &col, &row)) != 2)
        printf("Invalid input. Please re-enter:\n");
    
    chrocol(ch, col, row);

    return 0;
}

void chrocol(char ch, int col, int row)
{
    int n, m;
    for (n = 0; n < row; n++)
    {
        for (m = 0; m < col; m++)
            putchar(ch);
        printf("\n");
    }
}
