// 5. Design and test a function that searches the string specified by the first function
//    parameter for the first occurrence of a character specified by the second function
//    parameter. Have the function return a pointer to the character if successful, and a null
//    if the character is not found in the string. (This duplicates the way that the library
//    strchr() function works.) Test the function in a complete program that uses a loop to
//    provide input values for feeding to the function.

#include<stdio.h>
#include<string.h>
#define SIZE 40

char *StrChr(char *st, int c);
char *s_gets(char *st, int n);
int main(void)
{
    // declaration
    char array[SIZE];
    int c;
    char * ptr;

    // read a character and a string from 
    // which you want to find that character;
    puts("Enter a string of characters:");  
    s_gets(array, SIZE);
    puts("Enter the character you want to find:");
    c = getchar();
    getchar();     // discard newline character;

    // look for the character by StrChr() function
    ptr = StrChr(array, c);

    // print the result
    if (ptr)
        printf("%p\n", ptr);
    else if (ptr == NULL)
        puts("character not found.");
    puts("Done.");

    return 0;
}

char *s_gets(char *st, int n)         // define s_gets() to read a string
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
        else    // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char *StrChr(char *st, int c)
{
    while (*st != '\0')      // compare target character to each character 
    {                        // of the string if it is a not null character.
        if (*st == c)
           return st;        
        st++; 
    }
    return NULL;
}