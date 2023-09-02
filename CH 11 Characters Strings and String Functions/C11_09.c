// 9. Write a function that replaces the contents of a string with the string reversed. Test the
//    function in a complete program that uses a loop to provide input values for feeding to
//    the function.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char *s_gets(char *st, int n);
char *reverse(char *st, int n);
int main(void)
{
    char str[SIZE];      // declare an array
    
    puts("Enter a string of characters:");    // prompt for inpus
    while (s_gets(str, SIZE))                 // use while loop to provide input
    {
        puts(reverse(str, strlen(str)));      // call for reverse() function and print the result
        puts("Enter another string:");
    }
    puts("Done.");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else     // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char *reverse(char *st, int n)
{
    int temp;     // declare a temporary int to store 1 character
    int i = 0;    // declare a counter
    
    for (; i < n / 2; i++)    // use for loop to reverse the string
    {
        temp = st[i];         
        st[i] = st[n-i-1];
        st[n-i-1] = temp;
    }
    return st;                // return the pointer
}