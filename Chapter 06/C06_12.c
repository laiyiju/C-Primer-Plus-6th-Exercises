// 12. Consider these two infinite series:
//        1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
//        1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
//     Write a program that evaluates running totals of these two series up to some limit of
//     number of terms. Hint: –1 times itself an odd number of times is –1, and –1 times itself
//     an even number of times is 1. Have the user enter the limit interactively; let a zero or
//     negative value terminate input. Look at the running totals after 100 terms, 1000 terms,
//     10,000 terms. Does either series appear to be converging to some value?

#include<stdio.h>
int main(void)
{
    int lmt, i, m = -1;
    double sum1, sum2;

    printf("Enter a limit: ");
    scanf("%d", &lmt);

    while (lmt > 0)
    {
        sum1 = sum2 = 0;
        for (i = 1; i <= lmt; i++)
        {
            sum1 = sum1 + 1.0/(float)i;
            m *= -1;
            sum2 = sum2 + m/(float)i;
        }
        printf("the totals are %lf and %lf.\n", sum1, sum2);
        printf("Enter a new limit: ");
        scanf("%d", &lmt);
    }

    return 0;
}