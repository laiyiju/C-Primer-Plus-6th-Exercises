// 2. Modify and test the function in exercise 1 so that it stops after n characters or after the
//    first blank, tab, or newline, whichever comes first. (Don’t just use scanf().)

#include<stdio.h>
#include<string.h>
#include<ctype.h>                    // for the declaration of isspace() function
#define LEN 20

char * getstr(char * st, int n);
int main(void)
{
    char array[LEN];                 // declare an array to store chars
    char *check;

    puts("Enter some characters:");
    check = getstr(array, LEN);      // fetch, store chars and assign the ptr to check
    if (check == NULL)               // input failed (it could be intentional)
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
        else if (isspace(ch))      // Exit the loop if ch is a space, tab, or newline.
            break;
        st[i] = ch;
    }
    st[i] = '\0';                  // Null-terminate the string

    return st;
}