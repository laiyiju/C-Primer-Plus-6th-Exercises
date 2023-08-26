// 4. Design and test a function like that described in Programming Exercise 3 except that it
//    accepts a second parameter specifying the maximum number of characters that can be
//    read.

#include<stdio.h>
#include<ctype.h>           // declare isspace() function
#define LEN 20

char * getword(char *, int); 
int main(void)
{
    char array[LEN];        // declare an array to store a word

    puts("Enter a word(ctrl+D to quit):");
    while (getword(array, LEN) != NULL)   // call for getword() function
        puts(array);
    return 0;
}

char * getword(char * st, int n)
{
    int ch;
    char * ptr = st;

    while ((ch = getchar()) != EOF && isspace(ch))  // skip over initial whitespace
        continue;

    if (ch == EOF)
        return NULL;
    else
        *ptr++ = ch;      // first character in word

    while ((ch = getchar()) != EOF && !isspace(ch) && --n)  // get rest of word
        *ptr++ = ch;
    *ptr = '\0';          // end the string with a null character
    if (ch == EOF)
        return NULL;
    while (ch != '\n')      // discard the rest of the line
        ch = getchar();

    return st;
}