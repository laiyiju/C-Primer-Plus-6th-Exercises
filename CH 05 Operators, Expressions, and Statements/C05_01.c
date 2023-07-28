// 1. Write a program that converts time in minutes to time in hours and minutes. Use
//    #define or const to create a symbolic constant for 60. Use a while loop to allow the
//    user to enter values repeatedly and terminate the loop if a value for the time of 0 or less
//    is entered. 

#include<stdio.h>
#define MPH 60
int main(void)
{
    int minutes;
    int hours;
    int hmin;

    printf("Enter a time in minutes:\n");
    scanf("%d", &minutes);

    while (minutes > 0)
    {
        hours = minutes / MPH;
        hmin = minutes % MPH;
        printf("That equals %d hours and %d minutes.\n", hours, hmin);
        printf("Enter a time in minutes:\n");
        scanf("%d", &minutes);
    }

    return 0;
}
