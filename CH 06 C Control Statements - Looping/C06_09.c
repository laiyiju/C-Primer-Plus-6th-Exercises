// 9. Modify exercise 8 so that it uses a function to return the value of the calculation.

#include<stdio.h>
float cal(float n1, float n2);
int main(void)
{
    float n1, n2;
    printf("Enter 2 floating-point numbers: \n");

    while (scanf("%f %f", &n1, &n2) == 2)
        printf("their difference divided by their product is %9.2f\n", cal(n1, n2));

    return 0;
}

float cal(float n1, float n2)
{
    return (n1 - n2)/(n1 * n2);
}



