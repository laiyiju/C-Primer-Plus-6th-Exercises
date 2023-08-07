// 5. Write and test a function called larger_of() that replaces the contents of two double
//    variables with the maximum of the two values. For example, larger_of(x,y) would
//    reset both x and y to the larger of the two.

#include<stdio.h>

void larger_of(double * i, double * j);    // declaration of type pointer 
int main(void)
{
    double a, b;

    printf("Enter 2 numbers(q to quit):\n");
    while (scanf("%lf %lf", &a, &b) == 2)
    {
        larger_of(&a, &b);
        printf("1st number: %lf, 2nd number: %lf", a, b);
        printf("Enter another 2 numbers:\n");
    }
    printf("Done.\n");

    return 0;
}

void larger_of(double * i, double * j)
{
    *i = *j = (*i > *j ? *i : *j);     // ternary operator
}