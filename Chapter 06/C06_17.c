// 17. Chuckie Lucky won a million dollars (after taxes), which he places in an account that
//     earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a
//     program that finds out how many years it takes for Chuckie to empty his account.

#include<stdio.h>
#define WITHDR 100000.0f
#define RATE .08f
int main(void)
{
    int year;
    int total = 1000000.0f;         
    for (year = 0; total > 0; year++)
    {
        total *= 1.0f + RATE;
        total -= WITHDR;
    }
    printf("It took %d years for Chuckie to empty his account.\n", year);

    return 0;
}