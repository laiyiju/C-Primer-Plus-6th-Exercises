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

int menu(void);

void print_original_strings(const char st[][COL], int n);
void print_ASCII_order(char st[][COL], int n);
void print_increasing_length_order(char st[][COL], int n);
void print_first_word_length_order(char st[][COL], int n);

int main(void)
{
    char array_origin[ROW][COL];       // declare an array of 10 strings,
    char array_for_sorting[ROW][COL];
    int i = 0;                         // a counter,
    int choice;                        // and a variable to store user's choice.

    puts("Enter 10 strings.(press Ctrl+Z to end program):");    // promtp for input

    // Read strings while not exceeding the limit
    while (i < ROW && fgets(array_origin[i], COL, stdin) != NULL) 
    {
        // Remove the newline character if present
        size_t len = strlen(array_origin[i]);
        if (len > 0 && array_origin[i][len - 1] == '\n') 
        {
            array_origin[i][len - 1] = '\0'; // replace '\n' with '\0' to mark the end of a string
        }                                   
        i++;
    }

    // duplicate the original strings for later use
    for (int j = 0; j < ROW; j++)       
        strcpy(array_for_sorting[j], array_origin[j]);

    // print menu;
    puts("\nMake one choice from the menu:");                  
    puts("  1. Print the original list of strings");
    puts("  2. Print the strings in ASCII collating sequence");
    puts("  3. Print the strings in order of increasing length");
    puts("  4. Print the strings in order of the length of the first word in the string");
    puts("  5. Quit");

    // use a while loop to get user's choice
    while (scanf("%d", &choice))    
    {                              
        while (getchar() != '\n')
            continue;
        if (choice == 1)         
            print_original_strings(array_origin, i);    // use original array
        else if (choice == 2)
            print_ASCII_order(array_for_sorting, i);    // use duplicated array to prevent  
        else if (choice == 3)                           // changes to the the original one
            print_increasing_length_order(array_for_sorting, i);
        else if (choice == 4)
            print_first_word_length_order(array_for_sorting, i);
        else if (choice == 5)
            break;

        puts("\nNext choice(press 5 to quit):");        // prompt for the next input
    }
    puts("Done.");
    
    return 0;
}

// Function 1 (print the original list of strings)
void print_original_strings(const char st[][COL], int n)
{
    for (int i = 0; i < n; i++)
            puts(st[i]);
}

// Function 2 (print the strings in ASCII collating sequence)
void print_ASCII_order(char st[][COL], int n)
{
    char tmp[40];                        // declare a string 

    for (int i = 0; i < n; i++)          // outer loop to iterate through all the strings
    {
        for (int j = 1; i + j < n; j++)  // innter loop to iterate through all strings after st[i]
        {
            if (strncmp(st[i], st[i + j], COL) > 0)  // compare st[i] with the strings after it 
            {
                strcpy(tmp, st[i]);      // swap positions of st[i] and st[i + j]
                strcpy(st[i], st[i + j]);
                strcpy(st[i + j], tmp);
            }
        }
        puts(st[i]);                     // print the string.               
    }
}

// Function 3 (print the strings in order of increasing length)
void print_increasing_length_order(char st[][COL], int n)
{
    char tmp[40];                       // declare a string array

    for (int i = 0; i < n; i++)         // use an outer and an inner loop to sort the strings
    {             
        for (int j = 1; i + j < n; j++)
        {
            if (strlen(st[i]) > strlen(st[i + j]))
            {
                strcpy(tmp, st[i]);
                strcpy(st[i], st[i + j]);
                strcpy(st[i + j], tmp);
            }
        }
        puts(st[i]);                    // print the string.
    }
}

// Function 4 (print the strings in order of the length of the first word in the string)
void print_first_word_length_order(char st[][COL], int n)
{
    int len[ROW] = {0};                 // declare an integer string of ten '0's.    

    // a loop to calculate the length of the first word in each string
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int length = 0;

        while (isspace(st[i][j]))       // skip all whitespace characters at 
            j++;                        // the beginning of a string, if any

        // the end of a string is a null character which is not a white-space
        // so not being '\0' should be added to the condition of the loop
        while (!isspace(st[i][j]) && st[i][j] != '\0')  
        {
            length++;                   // count the length of the word
            j++;                        // increment j to keep updating the loop
        }
        len[i] = length;                // store the length into the declared array
    }

    char tmp_st[COL];                   // declare a string array
    int tmp_len;                        // declare an integer

    // Sort strings based on the length stored in the array len[ROW]
    for (int i = 0; i < n; i++)         
    {
        for (int j = 1; i + j < n; j++)
        {
            if (len[i] > len[i + j])
            {
                tmp_len = len[i];       // Swap lengths in len[]                         
                len[i] = len[i + j];
                len[i + j] = tmp_len;
                strncpy(tmp_st, st[i], COL);     // swap strings in st[]
                strncpy(st[i], st[i + j], COL);  
                strncpy(st[i + j], tmp_st, COL); 
            }
        }
        puts(st[i]);                    // print the sorted strings
    }
}
