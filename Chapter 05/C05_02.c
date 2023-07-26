// 2. Write a program that asks for an integer and then prints all the integers from (and
//    including) that value up to (and including) a value larger by 10. (That is, if the input is 5,
//    the output runs from 5 to 15.) Be sure to separate each output value by a space or tab or
//    newline. 

#include<stdio.h>
int main(void)
{
    int n;
    int count = 0;

    printf("Enter a number:\n");
    scanf("%d", &n);

    while (count++ < 11)
    {
        printf("%3d", n + count - 1);
    }

    return 0;
}
