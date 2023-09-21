// 11. Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
//     offer the user a menu with five choices: print the original list of strings, print the strings
//     in ASCII collating sequence, print the strings in order of increasing length, print the
//     strings in order of the length of the first word in the string, and quit. Have the menu
//     recycle until the user enters the quit request. The program, of course, should actually
//     perform the promised tasks.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ROW 10
#define COL 40

char *s_gets(char *st, int n);
int menu(void);

void print_original_strings(const char st[][COL], int n);
void print_ASCII_order(const char st[][COL], int n);
void print_increasing_length_order(const char st[][COL], int n);
void print_first_word_length_order(const char st[][COL], int n);

int main(void)
{
    char array[ROW][COL];  // declare an array of 10 strings,
    int i = 0;             // an integer as a counter,
    int choice;            // and an integer to store user's choice.

    puts("Enter up to 10 strings:");    // promtp for input
    while (i <= 10 && (s_gets(array[i], COL)) != NULL)    // use a while loop(i<10) to read in strings
        i++;

    puts("Make one choice from the menu:");     // print menu;
    puts("1. Print the original list of strings");
    puts("2. Print the strings in ASCII collating sequence");
    puts("3. Print the strings in order of increasing length");
    puts("4. Print the strings in order of the length of the first word in the string");
    puts("5. Quit");

    while (scanf("%d", choice))    // use a while loop to feed user's choice
    {                              // make a 5-choices structure with if-else statement
        if (choice == 1)           // call for different functions for each choice
            print_original_strings(array, COL);
        else if (choice == 2)
            print_ASCII_order(array, COL);
        else if (choice == 3)
            print_increasing_length_order(array, COL);
        else if (choice == 4)
            print_first_word_length_order(array, COL);
        else if (choice == 5)
            break;
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
        else    // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void print_original_strings(const char st[][COL], int n)
{
    while (st)
        puts(*st++);
}

void print_ASCII_order(const char st[][COL], int n)
{
    int ct1 = 0;                // declare an integer as an index
    
    while (st[ct1])             // use a loop to sort the strings
    {
        char *small = st + ct1;  // declare a pointer pointing at the string of smallest ASCII code
        int ct2 = 1;            // declare an integer as an index

        while (st[ct1 + ct2])      
        {
            if (strncmp(st[ct1], st[ct1 + ct2], n) > 0) 
                small = st + ct1 + ct2;
            ct2++;
        }
        puts(*small);            // print the string.
        ct1++;                  
    }
}

void print_increasing_length_order(const char st[][COL], int n)
{
    int ct1 = 0;                // declare an integer as an index

    while (st[ct1++])             // use a loop to sort the strings
    {
        char *first = st + ct1; // declare a pointer pointing at the string of smallest ASCII code
        int ct2 = 1;            // declare an integer as an index

        while (st[ct1 + ct2])
        {
            if (strlen(st[ct1]) > strlen(st[ct1 + ct2]))
                first = st + ct1 + ct2;
            ct2++;
        }
        puts(*first);            // print the string.
    }
}

void print_first_word_length_order(const char st[][COL], int n)
{
    int i = 0;
    int len[10] = {0,0,0,0,0,0,0,0,0,0};
    
    while (st[i])
    {
        int j = 0;
        int length = 0;

        while (isspace(st[i][j]))
            j++;

        while (!isspace(st[i][j]))
        {
            length++;
            j++;
        }
        len[i] = length;
        i++;
    }

    int ct1 = 0;
    while (len[ct1++])
    {
        int first = ct1;
        int ct2 = 1;
        while (len[ct1+ct2])
        {
            if (len[ct1] > len[ct1+ct2])
                first = ct1 + ct2;
            ct2++;
        }
        puts(st[first]);
    }
}
