// 9. Redo Programming Exercise 8, but this time use a recursive function.

#include<stdio.h>
double power(double, int);
int main(void)
{
    double n;
    int exp;

    printf("Enter a number and the positive integer power(q to quit):\n");
    while (scanf("%lf%d", &n, &exp) == 2)
    {
        if (n == 0 && exp == 0)
            printf("0 to the 0 power is undefined. Using a value of 1.\n");
        printf("%g to the power %d is %.5g.\n", n, exp, power(n, exp));
        printf("Enter the next number and its power:\n");
    }
    printf("Done.\n");

    return 0;
}

double power(double n, int exp)
{
    if (exp == 0)                       // zero power (also the end of recursion)
        return 1;
    else if (exp > 0)                   // positive power
        return power(n, exp - 1) * n;   
    if (exp < 0)                        // negative power
        return power(n, exp + 1) / n;
}