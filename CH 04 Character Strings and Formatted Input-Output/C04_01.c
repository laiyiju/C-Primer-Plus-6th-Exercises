// 1. Write a program that asks for your first name, your last name, and then prints the names
//    in the format last, first.

#include<stdio.h>
int main(void)
{
    char last[10];
    char first[10];

    printf("Enter your first name and last name:");
    scanf("%s %s", &first, &last);
    printf("%s, %s", last, first);

    return 0;
}
