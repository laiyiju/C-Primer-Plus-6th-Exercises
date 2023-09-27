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
    char array_origin[ROW][COL];  // declare an array of 10 strings,
    char array_for_sorting[ROW][COL];
    int i = 0;             // an integer as a counter,
    int choice;            // and an integer to store user's choice.

    puts("Enter 10 strings.(press Ctrl+Z to end program):");    // promtp for input

    // Read strings while not exceeding the limit
    while (i < ROW && fgets(array_origin[i], COL, stdin) != NULL) 
    {
        // Remove the newline character if present
        size_t len = strlen(array_origin[i]);
        if (len > 0 && array_origin[i][len - 1] == '\n') {
            array_origin[i][len - 1] = '\0';
        }
        i++;
    }

    for (int j = 0; j < ROW; j++)       // duplicate the original strings
        strcpy(array_for_sorting[j], array_origin[j]);

    puts("\nMake one choice from the menu:");     // print menu;
    puts("  1. Print the original list of strings");
    puts("  2. Print the strings in ASCII collating sequence");
    puts("  3. Print the strings in order of increasing length");
    puts("  4. Print the strings in order of the length of the first word in the string");
    puts("  5. Quit");

    while (scanf("%d", &choice))    // use a while loop to feed user's choice
    {                               // make a 5-choices structure with if-else statement
        while (getchar() != '\n')
            continue;
        if (choice == 1)            // call for different functions for each choice
            print_original_strings(array_origin, i);
        else if (choice == 2)
            print_ASCII_order(array_for_sorting, i);
        else if (choice == 3)
            print_increasing_length_order(array_for_sorting, i);
        else if (choice == 4)
            print_first_word_length_order(array_for_sorting, i);
        else if (choice == 5)
            break;

        puts("\nNext choice(press 5 to quit):");
    }
    puts("Done.");
    
    return 0;
}

void print_original_strings(const char st[][COL], int n)
{
    for (int i = 0; i < n; i++)
            puts(st[i]);
}

void print_ASCII_order(char st[][COL], int n)
{
    char tmp[40];

    for (int i = 0; i < n; i++){ // use a loop to sort the strings
        for (int j = 1; i + j < n; j++){
            if (strncmp(st[i], st[i + j], COL) > 0){
                strcpy(tmp, st[i]);
                strcpy(st[i], st[i + j]);
                strcpy(st[i + j], tmp);
            }
        }
        puts(st[i]);       // print the string.               
    }
}

void print_increasing_length_order(char st[][COL], int n)
{
    char tmp[40];                // declare a string array

    for (int i = 0; i < n; i++){             // use a loop to sort the strings
        for (int j = 1; i + j < n; j++){
            if (strlen(st[i]) > strlen(st[i + j])){
                strcpy(tmp, st[i]);
                strcpy(st[i], st[i + j]);
                strcpy(st[i + j], tmp);
            }
        }
        puts(st[i]);            // print the string.
    }
}

void print_first_word_length_order(char st[][COL], int n)
{
    int i = 0;
    int len[10] = {0,0,0,0,0,0,0,0,0,0};
    
    for (; i < n; i++){
        int j = 0;
        int length = 0;

        while (isspace(st[i][j]))
            j++;

        while (!isspace(st[i][j])){
            length++;
            j++;
        }
        len[i] = length;
    }

    char tmp[40];                // declare a string array
    for (i = 0; i < n; i++){
        for (int j = 1; i + j < n; j++){
            if (len[i] > len[i + j]){
                strcpy(tmp, st[i]);
                strcpy(st[i], st[i + j]);
                strcpy(st[i + j], tmp);
            }
        }
        puts(st[i]);
    }
}
