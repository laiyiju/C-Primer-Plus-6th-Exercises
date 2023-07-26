// 8. In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an
//    ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a
//    volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons,
//    and teaspoons. Why does a floating-point type make more sense for this application than
//    an integer type?

#include<stdio.h>
int main(void)
{
    float cup, pint, ounce, tablespoon, teaspoon;
    printf("Enter a volume in cups: ");
    scanf("%f", &cup);
    pint = cup / 2;
    ounce = cup * 8;
    tablespoon = ounce * 2;
    teaspoon = tablespoon * 3;
    printf("the volume in pints: %f\n", pint);
    printf("the volume in ounces: %f\n", ounce);
    printf("the volume in tablespoon: %f\n", tablespoon);
    printf("the volume in teaspoon: %f\n", teaspoon);

    return 0;
}
