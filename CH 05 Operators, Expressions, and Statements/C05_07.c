// 7. Write a program that requests a type double number and prints the value of the number
//    cubed. Use a function of your own design to cube the value and print it. The main()
//    program should pass the entered value to this function. 

#include<stdio.h>
void cube(double n);
int main(void) 
{
    double n;
    printf("Enter a type double number:\n");
    scanf("%lf", &n);
    cube(n);

    return 0;
}

void cube(double n)
{
    double m = n * n * n;
    printf("the cube of %lf is %lf.", n, m);
}
