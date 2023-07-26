// 6. Write a program that prints a table with each line giving an integer, its square, and its
//    cube. Ask the user to input the lower and upper limits for the table. Use a for loop.

#include<stdio.h>
int main(void)
{
    int start, end, n;
    printf("Enter the start and the end number: ");
    scanf("%d %d", &start, &end);

    printf("   n   n square   n cube");
    for (n = start; n <= end; n++)
        printf("%5d%9d%10d\n", n, n * n, n * n * n);
    
    return 0;
}