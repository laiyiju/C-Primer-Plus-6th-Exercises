// 9. Write a program that initializes a two-dimensional 3×5 array-of-double and uses a VLA-
//    based function to copy it to a second two-dimensional array. Also provide a VLA-based
//    function to display the contents of the two arrays. The two functions should be capable,
//    in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
//    compiler, use the traditional C approach of functions that can process an N×5 array).

#include<stdio.h>
#define ROWS 2
#define COLS 3

// declare VLAs
void copy2d(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void display(int rows, int cols, double ar[rows][cols]);

int main(void)
{
    // initialize VLAs with constants
    double sou[ROWS][COLS]= {{1.1, 3.3, 5.5}, {2.2, 4.4, 6.6}};
    double tar[ROWS][COLS];

    printf("source array: ");
    display(ROWS, COLS, sou);          // display source array
    copy2d(ROWS, COLS, tar, sou);      // copy 2-dimensional VLAs
    printf("target array: ");          
    display(ROWS, COLS, tar);          // display target array

    return 0;
}

void display(int rows, int cols, double ar[rows][cols])
{
    printf("{");
    for (int i = 0; i < rows; i++)
    {
        printf("{");
        for (int j = 0; j < cols; j++)
            printf(" %g ", ar[i][j]);
        printf("}");
    }
    printf("}\n");
}

void copy2d(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
}