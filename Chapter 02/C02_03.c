// 3. Write a program that converts your age in years to days and displays both values. At this
//    point, don’t worry about fractional years and leap years.

#include<stdio.h>
int main(void)
{
    int yearage, dayage;
    yearage = 34;
    dayage = yearage * 365;
    printf("I am %d years old and %d days old.\n",yearage,dayage);

    return 0;
}
