// 10. Write a function that takes a string as an argument and removes the spaces from the
//     string. Test it in a program that uses a loop to read lines until you enter an empty line.
//     The program should apply the function to each input string and display the result.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char *s_gets(char *st, int n);
char *remove_space(char *st);
int main(void)
{
    char array[SIZE];                           // declare a string
    
    puts("Enter a string with spaces in it:");  // prompt for input
    while (s_gets(array, SIZE))                 // use a while loop to provide input
    {
        puts(remove_space(array));              // call for remove_space() and print the result
        puts("Enter another string.");
    }
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}


char *remove_space(char *st)
{
    char *ptr = st;             // declare a pointer pointing to the start
    int i;

    while (*st)                 // use a while loop to iterate through string
    {
        if (*st == ' ')         // if it is a space character
        {                       
            i = 0;              // reset i to 0;
            while (st[i])       // use a while loop to move characters forward
            {
                st[i] = st[i + 1];   // replace it with the next char
                i++;                 // increment i
            }
        }
        else                         // when it is not a space,
            st++;                    // increment st.
    }
    return ptr;
}