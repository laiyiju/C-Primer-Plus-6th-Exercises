// 2. Write a program that asks you to enter an ASCII code value, such as 66, and then prints
//    the character having that ASCII code.

#include<stdio.h>
int main(void)
{
    int code_value;

    printf("Enter an ASCII code:");
    scanf("%d", &code_value);
    printf("The character that has %d as its ASCII code is %c", code_value, code_value);

    return 0;
}
