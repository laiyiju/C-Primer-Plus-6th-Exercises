// 3. Design and test a function that reads the first word from a line of input into an array and
//    discards the rest of the line. It should skip over leading whitespace. Define a word as a
//    sequence of characters with no blanks, tabs, or newlines in it. ??Use getchar(), not??

#include<stdio.h>
#include<ctype.h>           // declare isspace() function
#define LEN 20

char * getword(char * st); 
int main(void)
{
    char array[LEN];        // declare an array to store a word

    puts("Enter a word(ctrl+D to quit):");
    while (getword(array) != NULL)   // call for getword() function
        puts(array);
    return 0;
}

char * getword(char * st)
{
    int ch;
    char * ptr = st;

    while ((ch = getchar()) != EOF && isspace(ch))  // skip over initial whitespace
        continue;

    if (ch == EOF)
        return NULL;
    else
        *ptr++ = ch;      // first character in word

    while ((ch = getchar()) != EOF && !isspace(ch))  // get rest of word
        *ptr++ = ch;
    *ptr = '\0';          // end the string with a null character
    if (ch == EOF)
        return NULL;
    while (ch != '\n')      // discard the rest of the line
        ch = getchar();

    return st;
}