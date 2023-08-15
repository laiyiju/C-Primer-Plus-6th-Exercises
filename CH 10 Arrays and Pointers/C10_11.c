// 11. Write a program that declares a 3×5 array of int and initializes it to some values of
//     your choice. Have the program print the values, double all the values, and then display
//     the new values. Write a function to do the displaying and a second function to do the
//     doubling. Have the functions take the array name and the number of rows as arguments.

#include<stdio.h>
#define ROWS 3
#define COLS 5

void display(int [][COLS], int);       // ok to omit names when declaring
void double_ar(int [][COLS], int);
int main(void)
{
    int ar[ROWS][COLS] = {{1,4,7,10,13}, {2,5,8,11,14},{3,6,9,12,15}};  // initialization

    printf("original array: ");
    display(ar, ROWS);                 // display original array
    double_ar(ar, ROWS);               // double it
    printf("doubled array: ");         // display doubled array
    display(ar, ROWS);

    return 0;
}

void display(int ar[][COLS], int rows) // don't forget adding names when defining
{
    printf("{ ");
    for (int i = 0; i < rows; i++)
    {
        printf("{");
        for (int j = 0; j < COLS; j++)
            printf(" %d ", ar[i][j]);
        printf("} ");
    }
    printf("}\n");
}

void double_ar(int ar[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            ar[i][j] *= 2;
}