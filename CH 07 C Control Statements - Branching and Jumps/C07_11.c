// 11. The ABC Mail Order Grocery sells artichokes for $2.05 per pound, beets for $1.15 per
//     pound, and carrots for $1.09 per pound. It gives a 5% discount for orders of $100 or
//     more prior to adding shipping costs. It charges $6.50 shipping and handling for any
//     order of 5 pounds or under, $14.00 shipping and handling for orders over 5 pounds
//     and under 20 pounds, and $14.00 plus $0.50 per pound for shipments of 20 pounds or
//     more. Write a program that uses a switch statement in a loop such that a response of a
//     lets the user enter the pounds of artichokes desired, b the pounds of beets, c the pounds
//     of carrots, and q allows the user to exit the ordering process. The program should keep
//     track of cumulative totals. That is, if the user enters 4 pounds of beets and later enters
//     5 pounds of beets, the program should use report 9 pounds of beets. The program then
//     should compute the total charges, the discount, if any, the shipping charges, and the
//     grand total. The program then should display all the purchase information: the cost per
//     pound, the pounds ordered, and the cost for that order for each vegetable, the total cost
//     of the order, the discount (if there is one), the shipping charge, and the grand total of all
//     the charges.

#include<stdio.h>
#define PFA 2.05          // price for artichokes
#define PFB 1.15          // ......... beets
#define PFC 1.09          // ......... carrots

#define DSCT 0.05         // discount rate for orders of $100 or more
#define MIN 100           // The minimum purchase amount to qualify for the discount.

#define MAWE1 5           // maximum weight for the 1st tier shipping charge
#define MAWE2 20          // .......................2nd.....................

#define TIER1 6.50        // 1st tier shipping charge
#define TIER2 14.00       // 2nd.....................
#define TIER3 0.5         // 3rd tier charge per pound for weight over 20

int main(void)
{
    int choice;
    float weight, tweight;               // weight each time and total weight
    float total, discount, shipping, gtotal;
    float w1 = 0, w2 = 0, w3 = 0;        // weight of different vegetables 

    printf("Items in store:    1.artichokes       2.beets       3.carrots\n");
    printf("To choose the item above, enter a number (4 to exit the ordering process):\n");
    while (scanf("%d", &choice) == 1)                // 1. Input: choose a vegetable and specify
    {                                                //           its weight or exit.
        if (choice > 0 && choice <= 3)   
        {
            printf("Enter the weight: ");
            scanf("%f", &weight);                 
            switch (choice)
            {
                case 1: w1 += weight;
                        break;
                case 2: w2 += weight;
                        break;
                case 3: w3 += weight;
                        break;
            }
        }
        else if (choice == 4)
            break;
        else                                         //           if the input is invalid
            printf("Invalid input. Re-enter your choice:\n");

        printf("Choose the next item (4 to display the result):\n");
    }

    total = w1 * PFA + w2 * PFB + w3 * PFC;          // 2.1 total price calculation
    if (total >= MIN)                                // 2.2 discount calculation
        discount = total * DSCT;
    else
        discount = 0;
    tweight = w1 + w2+ w3;                           // 2.3 shipping charges calculation below:
    if (tweight <= MAWE1)                            //     if smaller than tier 1 maximum weight
        shipping = TIER1;
    else if (tweight >= MAWE2)                       //     if larger than tier 2 maximum weight
        shipping = TIER2;
    else                                             //     if between two maximum weight
        shipping = TIER2 + (tweight - MAWE2) * TIER3;
    gtotal = total - discount + shipping;            // 2.4 grand total calculation

    printf("-----------------------------------------------\n");       // 3. display the result
    printf("DESCRIPTION      WEIGHT(lb)   PRICE($)   COST($)\n");    
    printf("artichokes       %6.2f      %6.2f     %6.2f\n", w1, PFA, w1 * PFA);
    printf("beets            %6.2f      %6.2f     %6.2f\n", w2, PFB, w2 * PFB);
    printf("carrots          %6.2f      %6.2f     %6.2f\n", w3, PFC, w3 * PFC);
    printf("-----------------------------------------------\n");
    printf("   total    discount    shipping    grand total\n");
    printf("%8.2f%12.2f%12.2f%13.2f\n", total, discount, shipping, gtotal);

    return 0;
}
