// 7. Write a program that initializes a two-dimensional array-of-double and uses one of the
//    copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a
//    two-dimensional array is an array of arrays, a one-dimensional copy function can be used
//    with each subarray.)

#include<stdio.h>
#define ROWS 2
#define COLS 3

void display(double ar[][COLS], int r);    // be very careful about the declaration
void copy_arr(double tar[], double sou[], int n);
void copy2d(double [][COLS], double [][COLS], int r);
int main(void)
{
    double source[ROWS][COLS] = {{1.1, 3.3, 5.5},{2.2, 4.4, 6.6}};
    double target[ROWS][COLS];

    printf("The source array is: ");
    display(source, ROWS);                // display source array
    copy2d(target, source, ROWS);
    printf("The target array is: ");      // display target array
    display(target, ROWS);

    return 0;
}

void display(double ar[][COLS], int r)
{
    for (int i = 0; i < r; i++)
    {
        printf("{");
        for (int j = 0; j < COLS; j++)
            printf(" %g ", ar[i][j]);
        printf("} ");
    }
    printf("\n");
}

// one-dimentional copy function
void copy_arr(double tar[], double sou[], int n) 
{
    for (int i = 0; i < n; i++)
        tar[i] = sou[i];
}

// two-dimentional copy function
void copy2d(double tar[][COLS], double sou[][COLS], int r)
{
    for (int i = 0; i < r; i++)
        copy_arr(tar[i], sou[i], COLS);
}