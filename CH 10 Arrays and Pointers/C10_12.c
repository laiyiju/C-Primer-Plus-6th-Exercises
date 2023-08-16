// 12. Rewrite the rain program in Listing 10.7 so that the main tasks are performed by
//     functions instead of in main().

#include<stdio.h>
#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data

void yearly(const float ar[][MONTHS], int years);
void monthly(const float ar[][MONTHS], int years);
int main(void)
{
 // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    yearly(rain, YEARS);
    monthly(rain, YEARS);
    
    return 0;
}

void yearly(const float ar[][MONTHS], int years)
{
    float total = 0; 
    float subtot;

    printf(" YEAR    RAINFALL  (inches)\n");
    for (int year = 0; year < years; year++)
    {             
        // super confusing. If I put subtot's initialization after 'int month = 0' 
        // in the loop like the original listing 10.7, the final result of subtot
        // becomes 0. I don't understand. The same problem happens with 'total'.
        // I tried different compilers and the problem remains.
        subtot = 0;
        for (int month = 0; month < MONTHS; month++)
            subtot += ar[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;   // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);
}

void monthly(const float ar[][MONTHS], int years)
{
    float subtot;
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
    printf(" Nov Dec\n");

    for (int month = 0; month < MONTHS; month++)
    {              // for each month, sum rainfall over years
        subtot = 0;
        for (int year = 0; year < years; year++)
            subtot += ar[year][month];
        printf("%4.1f", subtot/YEARS);
    }
    printf("\n");

}
