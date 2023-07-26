// 13. Write a program that creates an eight-element array of ints and sets the elements to the
//     first eight powers of 2 and then prints the values. Use a for loop to set the values, and,
//     for variety, use a do while loop to display the values.

#include<stdio.h>
#define SIZE 8
int main(void)
{
    int i, powers[SIZE], pow2=1;

    for (i = 0; i < SIZE; i++)
    {
        powers[i] = pow2;
        pow2 *= 2;
    }
    i = 0;
    printf("Here is the values of the array: \n");
    do
    {
        printf("%d ", powers[i]);
        i++;
    } while (i < SIZE);

    return 0;
}