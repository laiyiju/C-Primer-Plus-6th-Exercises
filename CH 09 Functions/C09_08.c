// 8. Chapter 6, “C Control Statements: Looping,” ( Listing 6.20) shows a power() function
//    that returned the result of raising a type double number to a positive integer value.
//    Improve the function so that it correctly handles negative powers. Also, build into the
//    function that 0 to any power other than 0 is 0 and that any number to the 0 power is 1.
//    (It should report that 0 to the 0 is undefined, then say it’s using a value of 1.) Use a loop.
//    Test the function in a program.

#include<stdio.h>

double power(double, int);
int main(void)
{
    double n;
    int exp;

    printf("Enter a number and the positive integer power(q to quit):\n");
    while (scanf("%lf%d", &n, &exp) == 2)
    {
        printf("%g to the power %d is %.5g.\n", n, exp, power(n, exp));
        printf("Enter the next number and its power:\n");
    }
    printf("Done.\n");

    return 0;
}

double power(double n, int exp)
{
    double p = 1;     // 'exp'th power of 'n'
    int i;
    
    if (exp == 0)     
    {
        if (n == 0)
            printf("0 to the power 0 is undefined. A value of %g is used here.\n");
        p = 1;        // any number to the 0 power is 1
    }
    else if (exp > 0)
        for (i = 0; i < exp; i++)
        p *= n;
    else
        if (n == 0)
            p = 1; 
        for (i = 0; i > exp; i--)
            p /= n;

    return p;
}
