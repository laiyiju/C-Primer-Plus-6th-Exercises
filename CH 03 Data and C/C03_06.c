// 6. The mass of a single molecule of water is about 3.0×10-23 grams. A quart of water is
//    about 950 grams. Write a program that requests an amount of water, in quarts, and
//    displays the number of water molecules in that amount.

#include<stdio.h>
int main(void)
{
    int O2_mass;
    double molecules;
    
    printf("Enter the mass of the water in quarts:");
    scanf("%d", &O2_mass);

    molecules = O2_mass * 950 / 3e-23;

    printf("The number of water molecules in that amount is %e.\n", molecules);

    return 0;
}
