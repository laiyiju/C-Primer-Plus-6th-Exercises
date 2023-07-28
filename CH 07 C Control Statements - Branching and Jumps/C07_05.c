// 5. Redo exercise 4 using a switch. Requirements of excercise 4:
//      Using if else statements, write a program that reads input up to #, replaces each period
//      with an exclamation mark, replaces each exclamation mark initially present with two
//      exclamation marks, and reports at the end the number of substitutions it has made.

#include<stdio.h>
int main(void)
{
    int sub_ct = 0;
    char ch;

    printf("Enter some characters (enter '#' to exit):\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.':
                sub_ct++;
                printf("!");
                break;
            case '!':
                sub_ct++;
                printf("!!");
                break;
            default:
                putchar(ch);
                break;
        }
    }
    printf("The number of substitutions made: %d\n", sub_ct);

    return 0;
}