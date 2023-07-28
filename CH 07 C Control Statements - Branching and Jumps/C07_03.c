// 3. Write a program that reads integers until 0 is entered. After input terminates, the
//    program should report the total number of even integers (excluding the 0) entered, the
//    average value of the even integers, the total number of odd integers entered, and the
//    average value of the odd integers.

#include<stdio.h>
#define STOP 0               // for readability of the codes
int main(void)
{
    int input;
    int even_ct = 0, even_sum = 0;
    int odd_ct = 0, odd_sum = 0;

    printf("Enter a series of integers seperated by spaces\n");    // prompt for input
    printf("(End input with a 0.):\n");                            // tell users the way to end input
    while (scanf("%d", &input) == 1 && input != STOP)              // use scanf function as the test to avoid infinite loop
    {
        if (input % 2 == 0)                                        // when the input is even integer 
        {
            even_ct++;
            even_sum += input;
        }
        else                                                       // when the input is odd integer
        {
            odd_ct++;
            odd_sum += input;
        }
    }              
    printf("Total number of even integers: %d\n", even_ct);
    if (even_ct > 0)
        printf("Average value of the even integers: %.2f\n", (float)even_sum / even_ct); 
        // use cast operator to convert int to float
    printf("Total number of odd integers: %d\n", odd_ct);
    if (odd_ct > 0)
        printf("Average value of the odd integers: %.2f\n", (float)odd_sum / odd_ct);
    printf("Done.\n");

    return 0;
}