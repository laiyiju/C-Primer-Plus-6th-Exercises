// 4. Write a program that asks the user to enter a height in centimeters and then displays the
//    height in centimeters and in feet and inches. Fractional centimeters and inches should
//    be allowed, and the program should allow the user to continue entering heights until a
//    nonpositive value is entered. A sample run should look like this:
//       Enter a height in centimeters: 182
//       182.0 cm = 5 feet, 11.7 inches
//       Enter a height in centimeters (<=0 to quit): 168.7
//       168.0 cm = 5 feet, 6.4 inches
//       Enter a height in centimeters (<=0 to quit): 0
//       bye

#include<stdio.h>
#define CM_PER_FOOT 30.48

int main(void)
{
    float height, inches;
    int feet;
    
    printf("Enter a height in centimeters: ");
    scanf("%f", &height);

    while (height > 0)
    {
        feet = height / CM_PER_FOOT;
        inches = height - feet * CM_PER_FOOT;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
        printf("Enter a height in centimeters(<=0 to quit): ");
        scanf("%f", &height);
    }
    return 0;
}
