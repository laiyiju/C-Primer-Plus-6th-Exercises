// 11. Write a program that reads eight integers into an array and then prints them in reverse
//     order.

#include<stdio.h>
#define SIZE 8
int main(void)
{
    int index, num[SIZE];
    
    printf("Enter 8 integers: ");

    for (index = 0; index < SIZE; index++)
        scanf("%d", &num[index]);

    for (index = SIZE - 1; index >= 0; index--)
        printf("%d", num[index]);
    printf("\n");
    
    return 0;
}