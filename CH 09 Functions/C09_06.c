// 6. Write and test a function that takes the addresses of three double variables as arguments
//    and that moves the value of the smallest variable into the first variable, the middle value
//    to the second variable, and the largest value into the third variable.

#include<stdio.h>

void sort_ascending(double *p1, double *p2, double *p3);
int main(void)
{
    double n1, n2, n3;

    printf("Enter 3 numbers(q to quit):\n");
    while (scanf("%lf%lf%lf", &n1, &n2, &n3) == 3)
    {
        sort_ascending(&n1, &n2, &n3);
        printf("After sorting:\n");
        printf("x: %lf, y: %lf, z: %lf\n", n1, n2, n3);
        printf("Enter another 3 numbers:\n");
    }
    printf("Done.\n");

    return 0;
}

void sort_ascending(double *p1, double *p2, double *p3)
{
    double temp;
    
    // bubble sort
    if (*p1 > *p2)         
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }

    if (*p2 > *p3)
    {
        temp = *p3;
        *p3 = *p2;
        *p2 = temp;

        if (*p1 > *p2)
        {
            temp = *p2;
            *p2 = *p1;
            *p1 = temp;
        }
    }
}