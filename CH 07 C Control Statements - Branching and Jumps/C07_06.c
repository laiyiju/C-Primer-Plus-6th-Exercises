// 6. Write a program that reads input up to # and reports the number of times that the
//    sequence ei occurs.
//    **Note:
//      The program will have to “remember” the preceding character as well as the current character.
//      Test it with input such as “Receive your eieio award.”

#include<stdio.h>
int main(void)
{
    int ei_ct;
    char c_ch, p_ch;            // current character & preceding character

    printf("Enter characters (enter '#' to exit):\n");
    while ((c_ch = getchar()) != '#')
    {
        if (c_ch == 'e')
            p_ch = c_ch;
        else if (p_ch == 'e' && c_ch == 'i')
            ei_ct++;
    }
    printf("the number of times that the sequence ei occurs: %d", ei_ct);

    return 0;
}