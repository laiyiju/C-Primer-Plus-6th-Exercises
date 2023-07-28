// 14. Write a program that creates two eight-element arrays of doubles and uses a loop to let
//     the user enter values for the eight elements of the first array. Have the program set the
//     elements of the second array to the cumulative totals of the elements of the first array.
//     For example, the fourth element of the second array should equal the sum of the first
//     four elements of the first array, and the fifth element of the second array should equal
//     the sum of the first five elements of the first array. (It’s possible to do this with nested
//     loops, but by using the fact that the fifth element of the second array equals the fourth
//     element of the second array plus the fifth element of the first array, you can avoid
//     nesting and just use a single loop for this task.) Finally, use loops to display the contents
//     of the two arrays, with the first array displayed on one line and with each element of the
//     second array displayed below the corresponding element of the first array.

#include<stdio.h>
#define SIZE 8
int main(void)
{
    double a1[SIZE], a2[SIZE], sum = 0;
    int i;
    printf("Enter 8 numbers: ");
    
    for (i = 0; i < SIZE; i++)
    {
        scanf("%lf", &a1[i]);
        sum += a1[i];
        a2[i] = sum;
    }
    
    for (i = 0; i < SIZE; i++)
    {
        printf("%10.2lf", a1[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%10.2lf", a2[i]);
    }

    return 0;
}