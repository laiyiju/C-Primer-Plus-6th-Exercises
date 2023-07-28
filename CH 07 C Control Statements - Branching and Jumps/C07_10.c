// 10. The 1988 United States Federal Tax Schedule was the simplest in recent times. It had
//     four categories, and each category had two rates. Here is a summary (dollar amounts are
//     taxable income):
//     Category               Tax
//        Single              15% of first $17,850 plus 28% of excess
//        Head of Household   15% of first $23,900 plus 28% of excess
//        Married, Joint      15% of first $29,750 plus 28% of excess
//        Married, Separate   15% of first $14,875 plus 28% of excess
//     For example, a single wage earner with a taxable income of $20,000 owes 0.15 × $17,850
//     + 0.28 × ($20,000−$17,850). Write a program that lets the user specify the tax category
//     and the taxable income and that then calculates the tax. Use a loop so that the user can
//     enter several tax cases.

#include<stdio.h>
#define RATE1 0.15
#define RATE2 0.28
#define CATG1 17850
#define CATG2 23900
#define CATG3 29750
#define CATG4 14875

int main(void)
{
    int income;
    int RSP;           // rate switching point
    int choice;
    float tax;

    printf("To calculate the tax, choose a category first: \n");
    printf("1. Single                 2. Head of Household\n");
    printf("3. Married, Joint         4. Married, Separate\n");
    printf("5. Quit\n");
    while (scanf("%d", &choice) == 1)
    {
        if (choice == 5)                         // quit
            break;
        else
            switch (choice)                      // choose a category
            {
                case 1: RSP = CATG1;
                        break;
                case 2: RSP = CATG2;
                        break;
                case 3: RSP = CATG3;
                        break;
                case 4: RSP = CATG4;
                        break;
            }
        
        printf("Enter a taxable income:\n");
        while (scanf("%d", &income) == 1 && income > 0)  // loop for calculation
        {
            if (income < RSP)
                tax = income * RATE1;
            else
                tax = RSP * RATE1 + (income - RSP) * RATE2;
            printf("Taxable income: %d  Tax: %.2f\n", income, tax);
            printf("*****************************************");
            printf("Enter a new case(q to change category or quit):");
        }
        scanf("%*s");                // dispose of "q" in the buffer
        printf("Choose another category(q to exit):\n");
    }

    return 0;
}