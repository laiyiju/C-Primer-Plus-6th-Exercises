// 13. Write a program that prompts the user to enter three sets of five double numbers each.
//     (You may assume the user responds correctly and doesn’t enter non-numeric data.) The
//     program should accomplish all of the following:
//        a. Store the information in a 3×5 array.
//        b. Compute the average of each set of five values.
//        c. Compute the average of all the values.
//        d. Determine the largest value of the 15 values.
//        e. Report the results.
//     Each major task should be handled by a separate function using the traditional C
//     approach to handling arrays. Accomplish task “b” by using a function that computes
//     and returns the average of a one-dimensional array; use a loop to call this function three
//     times. The other tasks should take the entire array as an argument, and the functions
//     performing tasks “c” and “d” should return the answer to the calling program.

#include<stdio.h>
#define ROWS 3
#define COLS 5

// function prototypes for each task
void create_array(double ar[][COLS], int rows);     
double get_subavg(double ar[], int cols);           
double get_totavg(double ar[][COLS], int rows);
double get_largest(double ar[][COLS], int rows);
void display(double avg, double largest);

int main(void)
{
    double array[ROWS][COLS];
    double subavg, totavg, largest;

    create_array(array, ROWS);                  // task a
    printf("The averages of each set of 5 numbers: ");
    for (int i = 0; i < ROWS; i++)              
    {
        subavg = get_subavg(array[i], COLS);    // task b
        printf(" %g ", subavg);
    }
    totavg = get_totavg(array, ROWS);           // task c
    largest = get_largest(array, ROWS);         // task d
    display(totavg, largest);                   // task e
    
    return 0;
}

void create_array(double ar[][COLS], int rows)
{
    printf("Enter values for a 3x5 array:\n");
    // read numbers and assign them to the argument array using for loop
    for (int r = 0; r < rows; r++)              
        for (int c = 0; c < COLS; c++)
            scanf("%lg", &ar[r][c]);   // %lg indicate that the value will be stored in type double

    // display the array to check if the input is correct or not
    printf("Here is the array:\n{ ");
    for (int r = 0; r < rows; r++){
        printf("{ ");
        for (int c = 0; c < COLS; c++)
            printf("%g ", ar[r][c]);
        printf("} ");
    }
    printf("}\n");
}

double get_subavg(double ar[], int cols)  // function to get the average of a 1-dimensional array
{
    double total = 0;

    for (int c = 0; c < cols; c++)
        total += ar[c];
    
    return total/cols;
}

double get_totavg(double ar[][COLS], int rows) // function to get the average of a 2-d array
{
    double total = 0;

    for (int r = 0; r < rows; r++){
        double subtot = 0;
        for (int c = 0; c < COLS; c++)
            subtot += ar[r][c];
        total += subtot;
    }
    
    return total/(rows * COLS);    
}

double get_largest(double ar[][COLS], int rows) // function to get the largest of a 2d array
{
    double max = ar[0][0];

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < COLS; c++)
            max = max < ar[r][c] ? ar[r][c] : max;

    return max;
}

void display(double avg, double largest)  // display the result
{
    printf("\nThe average of all the values: %g\n", avg);
    printf("The largest of them: %g\n", largest);
}