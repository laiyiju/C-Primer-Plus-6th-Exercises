// 7. Many studies suggest that smiling has benefits. Write a program that produces the
//    following output:
//        Smile!Smile!Smile!
//        Smile!Smile!
//        Smile!
//    Have the program define a function that displays the string Smile! once, and have the
//    program use the function as often as needed.

#include<stdio.h>
void smile(void);               // ANSI/ISO C function prototyping

int main(void)
{
    smile(); smile(); smile();  // function call
    printf("\n");
    smile(); smile();
    printf("\n");
    smile();

    return 0;
}

void smile(void)                // function definition
{
    printf("Smile!");
}
