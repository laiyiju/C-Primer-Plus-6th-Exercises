// 8. Write a program that asks the user to enter the number of miles traveled and the number
//    of gallons of gasoline consumed. It should then calculate and display the miles-per-gallon
//    value, showing one place to the right of the decimal. Next, using the fact that one gallon
//    is about 3.785 liters and one mile is about 1.609 kilometers, it should convert the mile-
//    per-gallon value to a liters-per-100-km value, the usual European way of expressing fuel
//    consumption, and display the result, showing one place to the right of the decimal. Note
//    that the U. S. scheme measures the distance traveled per amount of fuel (higher is better),
//    whereas the European scheme measures the amount of fuel per distance (lower is better).
//    Use symbolic constants (using const or #define) for the two conversion factors.

#include<stdio.h>
#define GALLON 3.785
#define MILE 1.609
int main(void)
{
    float distance, fuel;
    float mpg;   // miles per gallon
    float lpk;   // liters per 100km

    printf("Enter the number of miles traveled and the number of gallons of gasoling consumed: \n");
    scanf("%f %f", &distance, &fuel);
    
    mpg = distance / fuel;
    printf("miles-per-gallon: %.1f\n", mpg); 
    lpk = (fuel * GALLON) / (distance * MILE / 100);
    printf("liters per 100km: %.1f\n", lpk);

    return 0;
}
