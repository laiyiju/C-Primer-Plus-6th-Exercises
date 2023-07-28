// 9. Write a program that accepts a positive integer as input and then displays all the prime
//    numbers smaller than or equal to that number.
#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    int input, prime, divisor;
    bool isPrime;                                     // prime flag

    printf("Enter a positive integer(q to quit): \n");
    while (scanf("%d", &input) == 1)                  // 1st loop for input
    {
        if (input < 2)                                // if the input is invalid
            printf("Input should be no less than 2.\n");
        else                                          // if the input is valid
        {
            printf("Here are the prime numbers up through %d:\n", input);
            for (prime = 2; prime <= input; prime++)  // 2nd loop for all integers smaller than the input
            {
                for (divisor = 2; isPrime = true, (divisor * divisor) <= prime; divisor++)  // 3rd loop to find primes
                    if (prime % divisor == 0)         // Evenly divided. Not prime
                    {
                        isPrime = false;
                        break;
                    } 
                if (isPrime)
                    printf("%-5d", prime);             // Print the prime
            }
        }
        printf("Enter a new integer(q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}