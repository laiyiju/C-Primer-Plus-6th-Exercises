// 4. Write a program that produces the following output:
//        For he's a jolly good fellow!
//        For he's a jolly good fellow!
//        For he's a jolly good fellow!
//        Which nobody can deny!
//    Have the program use two user-defined functions in addition to main(): one named
//    jolly() that prints the “jolly good” message once, and one named deny() that prints
//    the final line once.

#include<stdio.h>
void jolly(void);        // ANSI/ISO C function prototyping, informing the compiler about the functions to be used
void deny(void);             
int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();
    
    return 0;
}

void jolly(void)           // start of function definition
{
    printf("For he's jolly good fellow!\n");
}

void deny(void)           // start of function definition
{
    printf("Which nobody can deny!\n");
}
