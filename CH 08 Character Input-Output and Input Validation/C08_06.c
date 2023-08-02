// 6. Modify the get_first() function of Listing 8.8 so that it returns the first non-
//    whitespace character encountered. Test it in a simple program.

#include<stdio.h>
char get_first(void);
int main(void)
{
    char ch;

    printf("Enter some characters:\n");
    ch = get_first();
    putchar(ch);

    return 0;
}

char get_first(void)
{
    int ch;

    // if the beginning of the input is space or tab character, it goes into
    // the first while loop to dispose them, and when it encounters the first 
    // non-whitespace character, it will be stored in ch without going into 
    // the loop. And the rest of the input will be disposed by the second loop.
 
    while ((ch = getchar()) == ' ' || ch == '\t' || ch == '\n') 
    // (notice: whitespace character includes blank, tab and newline.)
        continue;
    while (getchar() != '\n')
        continue;

    return ch;
}