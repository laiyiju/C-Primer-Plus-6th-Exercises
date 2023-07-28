// 1. Write a program that reads input until encountering the # character and then reports
//    the number of spaces read, the number of newline characters read, and the number of all
//    other characters read.

#include<stdio.h>
int main(void)
{
    char ch;                            
    int space_ct = 0;                       // spaces read
    int newline_ct = 0;                     // newline read
    int other_ct = 0;                       // other char read

    printf("Enter some characters: \n");

    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space_ct++;
        else if (ch == '\n')
            newline_ct++;
        else
            other_ct++;
    }
    printf("There are %d space characters, %d newline\n", space_ct, newline_ct);
    printf("characters and %d other characters.\n", other_ct);

    return 0;
}