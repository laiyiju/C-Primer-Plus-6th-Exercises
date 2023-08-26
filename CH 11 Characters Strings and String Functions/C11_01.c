// 1. Design and test a function that fetches the next n characters from input (including
//    blanks, tabs, and newlines), storing the results in an array whose address is passed as an
//    argument.

#include<stdio.h>
#include<string.h>
#define LEN 20

char * getstr(char * st, int n);
int main(void)
{
    char array[LEN];                 // declare an array to store chars
    char *check;

    puts("Enter some characters:");
    check = getstr(array, LEN);      // fetch, store chars and assign the ptr to check
    if (check == NULL)               // input failed
        puts("Input failed.");
    else                             // input succeeded
        puts(array);
    puts("Done.\n");
    
    return 0;
}

char * getstr(char * st, int n)
{    
    int ch;                         // declare an integer variable to store character 
    int i = 0;                      // declare an integer as a counter

    for (; i < n; i++)
    {
        ch = getchar();
        if (ch == EOF)             // If the loop ends with a character being EOF.        
            return NULL;           // Returns a NULL pointer to indicate input failure.
        st[i] = ch;
    }
    st[i] = '\0';                  // Null-terminate the string

    return st;
}