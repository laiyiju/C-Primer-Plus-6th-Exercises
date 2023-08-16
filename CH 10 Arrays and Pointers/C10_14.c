// 14. Do Programming Exercise 13, but use variable-length array function parameters.

#include<stdio.h>
#define ROWS 3
#define COLS 5

// function prototypes for each task. take VLAs as arguments.
void create_array(int rows, int cols, double ar[rows][cols]); 
double get_subavg(int cols, double ar[cols]);           
double get_totavg(int rows, int cols, double ar[rows][cols]);
double get_largest(int rows, int cols, double ar[rows][cols]);
void display(double avg, double largest);

int main(void)
{
    double array[ROWS][COLS];
    double subavg, totavg, largest;

    create_array(ROWS, COLS, array);                  // task a
    printf("The averages of each set of 5 numbers: ");
    for (int i = 0; i < ROWS; i++)              
    {
        subavg = get_subavg(COLS, array[i]);          // task b
        printf(" %g ", subavg);
    }
    totavg = get_totavg(ROWS, COLS, array);           // task c
    largest = get_largest(ROWS, COLS, array);         // task d
    display(totavg, largest);                         // task e
    
    return 0;
}

void create_array(int rows, int cols, double ar[rows][cols])
{
    printf("Enter values for a 3x5 array:\n");
    // read numbers and assign them to the argument array using for loop
    for (int r = 0; r < rows; r++)              
        for (int c = 0; c < cols; c++)
            scanf("%lg", &ar[r][c]);   // %lg indicate that the value will be stored in type double

    // display the array to check if the input is correct or not
    printf("Here is the array:\n{ ");
    for (int r = 0; r < rows; r++){
        printf("{ ");
        for (int c = 0; c < cols; c++)
            printf("%g ", ar[r][c]);
        printf("} ");
    }
    printf("}\n");
}

double get_subavg(int cols, double ar[cols])  // function to get the average of a 1-dimensional array
{
    double total = 0;

    for (int c = 0; c < cols; c++)
        total += ar[c];
    
    return total/cols;
}

double get_totavg(int rows, int cols, double ar[rows][cols]) // function to get the average of a 2-d array
{
    double total = 0;

    for (int r = 0; r < rows; r++){
        double subtot = 0;
        for (int c = 0; c < cols; c++)
            subtot += ar[r][c];
        total += subtot;
    }
    
    return total/(rows * cols);    
}

double get_largest(int rows, int cols, double ar[rows][cols]) // function to get the largest of a 2d array
{
    double max = ar[0][0];

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            max = max < ar[r][c] ? ar[r][c] : max; 

    return max;
}

void display(double avg, double largest)  // display the result
{
    printf("\nThe average of all the values: %g\n", avg);
    printf("The largest of them: %g\n", largest);
}