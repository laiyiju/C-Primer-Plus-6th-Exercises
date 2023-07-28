// 4. Using if else statements, write a program that reads input up to #, replaces each period
//    with an exclamation mark, replaces each exclamation mark initially present with two
//    exclamation marks, and reports at the end the number of substitutions it has made.

#include<stdio.h>
int main(void)
{
    int sub_ct = 0;
    char ch;

    printf("Enter some characters (enter '#' to exit):\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            sub_ct++;
            printf("!");
        }
        else if (ch == '!')
        {
            sub_ct++;
            printf("!!");
        }
        else
            printf("%c", ch);
    }
    printf("The number of substitutions made: %d\n", sub_ct);

    return 0;
}