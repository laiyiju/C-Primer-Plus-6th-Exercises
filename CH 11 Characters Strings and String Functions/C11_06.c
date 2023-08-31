// 6. Write a function called is_within() that takes a character and a string pointer as its two
//    function parameters. Have the function return a nonzero value (true) if the character is
//    in the string and zero (false) otherwise. Test the function in a complete program that uses
//    a loop to provide input values for feeding to the function.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char * s_gets(char *st, int n);
_Bool is_within(int c, const char * st);
int main(void)
{
    // declaration of an array of characters
    char array[SIZE];
    int c, i;
    _Bool result;
    
    puts("Enter a string of characters:");      // prompt for input
    // start a while loop to provide input
    while (s_gets(array, SIZE) && array[0] != '\0')
    {
        puts("Enter the character you want to check:");
        c = getchar();
        getchar();                       // discard newline

        result = is_within(c, array);    // call for is_winthin
                                    
        if (result)                      // print the result
            printf("character '%c' is in the string.\n", c);
        else
            printf("character '%c' is not in the string.\n", c);       

        // continue reading input
        puts("Enter a string of characters:");  // prompt for input
    }
    return 0;
}

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');  // use strchr() to find newline
        if (find)                 // if the address is not NULL,
            *find = '\0';         // place a null character there
        else   // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val; 
}

_Bool is_within(int c, const char * st)
{
    while (*st != c && *st != '\0')
        st++;
    return *st;   // = 0 if \0 reached, non-zero otherwise
}