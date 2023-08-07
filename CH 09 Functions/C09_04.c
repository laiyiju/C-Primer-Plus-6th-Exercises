// 4. The harmonic mean of two numbers is obtained by taking the inverses of the two
//    numbers, averaging them, and taking the inverse of the result. Write a function that
//    takes two double arguments and returns the harmonic mean of the two numbers.

#include<stdio.h>

double hmean(double, double);
int main(void)
{
    double a, b;
    
    printf("Enter 2 numbers(q to quit):\n");
    while(scanf("%lf %lf", &a, &b) == 2)
    {
        printf("The harmonic mean of %.2lf and %.2lf is %.2lf.", 
                a, b, hmean(a, b));
        printf("Enter another 2 numbers:\n");
    }
    printf("Done.\n");

    return 0;
}

double hmean(double a, double b)       // harmonic mean calculation
{  
    return 2 / (1 / a + 1 / b);
}