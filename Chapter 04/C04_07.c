// 7. Write a program that sets a type double variable to 1.0/3.0 and a type float variable
//    to 1.0/3.0. Display each result three times—once showing four digits to the right of the
//    decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits
//    to the right of the decimal. Also have the program include float.h and display the
//    values of FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these
//    values? 

#include<stdio.h>
#include<float.h>
int main(void)
{
    double dnum = 1.0/3.0;
    float fnum = 1.0/3.0;

    printf("double values: %.4f %.12f %.16lf\n", dnum, dnum, dnum);
    printf("float values: %.4f %.12f %.16lf\n", fnum, fnum, fnum);
    printf("FLT_DIG: %d\n DBL_DIG: %d\n", FLT_DIG, DBL_DIG);

    return 0;
}
