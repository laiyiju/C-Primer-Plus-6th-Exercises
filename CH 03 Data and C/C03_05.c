// 5. There are approximately 3.156 × 107 seconds in a year. Write a program that requests
//    your age in years and then displays the equivalent number of seconds.

#include<stdio.h>
int main(void)
{
    int year_age;
    double sec_age = year_age * 3.156e7;

    printf("Enter your age in years:");
    scanf("%d", &year_age);                   
    printf("Your age in seconds is %e.\n", sec_age);

    return 0;
}
