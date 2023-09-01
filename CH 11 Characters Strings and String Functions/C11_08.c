// 8. Write a function called string_in() that takes two string pointers as arguments. If
//    the second string is contained in the first string, have the function return the address
//    at which the contained string begins. For instance, string_in("hats", "at") would
//    return the address of the a in hats. Otherwise, have the function return the null pointer.
//    Test the function in a complete program that uses a loop to provide input values for
//    feeding to the function.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char *s_gets(char *st, int n);
char *string_in(const char *s1, const char *s2);// add 'const' to protect original data
int main(void)
{
    char s1[SIZE], s2[SIZE];                    // declare 2 arrays to store strings
    char *result;
    
    puts("Enter the first string:");            // prompt for input
    while (s_gets(s1, SIZE))                    // use while loop for input
    {
        puts("Enter the second string:");
        s_gets(s2, SIZE);
        result = string_in(s1, s2);             // call for string_in() function
        if (result)                             // print the result
            puts("The 2nd string is in the 1st string.");
        else
            puts("The 2nd string is not in the 1st string.");
        puts("Enter the first string:");
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
        else    
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char *string_in(const char *s1, const char *s2)        
{
    int len2 = strlen(s2);
    int i = 0;
    
    while (s1[i] != '\0' && strlen(s1) - i >= len2)    // while loop for s1's characters. Make sure that even after 
    {                                                  // increment, s1 still has enough chars to compare with s2.
        if (!strncmp(s1 + i, s2, len2))  // when the return value of strncmp() is 0,   
            return (char *)(s1 + i);     // meaning that s2 is in s1, return s1. 
        else                             // otherwise ('else' is dispensible)
            i++;                         // increment i.
    }
    return NULL;                         // s2 is not found in s1 after the loop, return NULL.
}