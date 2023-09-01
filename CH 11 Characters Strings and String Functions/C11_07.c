// 7. The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating
//    s2 or padding it with extra null characters as necessary. The target string may not be
//    null-terminated if the length of s2 is n or more. The function returns s1. Write your own
//    version of this function; call it mystrncpy(). Test the function in a complete program
//    that uses a loop to provide input values for feeding to the function.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char *s_gets(char *st, int n);
char * mystrncpy(char *source, char *target, int n);
int main(void)
{
    char arr1[SIZE], arr2[SIZE];        // declare 2 strings 
    int ch;                             // 1 char variable
    int n = 10;                         // and the length of the copy

    puts("Enter characters as the source string:");
    while (s_gets(arr1, SIZE) != NULL)  // use while loop to provide input
    {
        mystrncpy(arr1, arr2, n);       // call for mystrncpy() to copy string
        puts(arr2);                     // print the result
        puts("Enter the next source string:");
    }
    puts("Done.");
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

char * mystrncpy(char *source, char *target, int n)
{
    for (int i = 0; i < n; i++)         // use for loop to copy characters 1 by 1
    {
        if (source[i] != '\0')          // if source[i] is not '\0', keep copying
            target[i] = source[i];  
        else                            // if source[i] is '\0', padding the target
            target[i] = '\0';           // with extra '\0'
    }
    return target;                      // return source's pointer name.
}