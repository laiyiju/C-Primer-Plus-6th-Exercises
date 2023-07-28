// 4. Write a program that requests your height in inches and your name, and then displays 
//    the information in the following form:
//        Dabney, you are 6.208 feet tall
//    Use type float, and use / for division. If you prefer, request the height in
//    centimeters and display it in meters.

#include<stdio.h>
int main(void)
{
    float height;
    char name[10];

    printf("Enter your height and name: \n");
    scanf("%f%s", &height, &name);
    printf("%s, you are %0.3f feet tall\n", name, height);

    return 0;
}
