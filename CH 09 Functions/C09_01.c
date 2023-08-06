// 1. Devise a function called min(x,y) that returns the smaller of two double values. Test
//    the function with a simple driver.

#include<stdio.h>
double min(double, double);     // declare function prototype

int main(void)
{
    double a, b;

    printf("Enter two double values separated by space:\n");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        printf("%lf is the smaller number.\n",min(a, b));    // function call
        printf("Enter new numbers:\n");
    }
    printf("Done.\n");

    return 0;
}

double min(double x, double y)
{
    return x < y ? x : y;       // ternary operator
}
