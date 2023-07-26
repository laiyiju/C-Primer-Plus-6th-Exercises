// 7. There are 2.54 centimeters to the inch. Write a program that asks you to enter your
//    height in inches and then displays your height in centimeters. Or, if you prefer, ask for
//    the height in centimeters and convert that to inches.

#include<stdio.h>
int main(void)
{
    float height_cm;
    float height_in;

    printf("Enter your height in centimeters: ");
    scanf("%f", &height_cm);
    
    height_in = height_cm / 2.54;
    printf("Your height in inches is %f.\n", height_in);

    return 0;
}
