// 8. Modify assumption a. in exercise 7 so that the program presents a menu of pay rates
//    from which to choose. Use a switch to select the pay rate. The beginning of a run
//    should look something like this:
//    *****************************************************************
//    Enter the number corresponding to the desired pay rate or action:
//     1) $8.75/hr                  2) $9.33/hr
//     3) $10.00/hr                 4) $11.20/hr
//     5) quit
//    *****************************************************************
//    If choices 1 through 4 are selected, the program should request the hours worked. The
//    program should recycle until 5 is entered. If something other than choices 1 through 5
//    is entered, the program should remind the user what the proper choices are and then
//    recycle. Use #defined constants for the various earning rates and tax rates.

#include<stdio.h>
#define BR1 8.75              // basic rate tier 1
#define BR2 9.33              // ............... 2
#define BR3 10.00             // ............... 3
#define BR4 11.20             // ............... 4
#define OT_RATE 15.00         // overtime pay rate

#define B_HR 40               // basic work hours

#define T_RATE1 0.15          // tax rate of first $300
#define T_RATE2 0.20          // tax rate of the next $150
#define T_RATE3 0.25          // tax rate of the rest

#define T_LVL1 300.00
#define T_LVL2 450.00

int main(void)
{
    float hr, b_rate, gpay, tax, npay;
    int choice;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%.2f/hr                   2) $%.2f/hr\n", BR1, BR2);
    printf("3) $%.2f/hr                  4) $%.2f/hr\n", BR3, BR4);
    printf("5) quit\n");
    printf("*****************************************************************\n");

    while (scanf("%d", &choice))                    
    {
        if (choice > 0 && choice < 5)               // choose a basic rate
            switch (choice)                         
            {
                case 1: b_rate = BR1;
                        break;
                case 2: b_rate = BR2;
                        break;
                case 3: b_rate = BR3;
                        break;
                case 4: b_rate = BR4;
                        break;
            }
        else if (choice == 5)                       // quit the program
        {    
            printf("Done.\n");                      
            break;
        }
        else                                        // require a proper input
        {
            printf("Invalid input. Please enter an integer from 1 through 4:\n");
            continue;
        }
    
        printf("Enter the hours worked in a week:\n");
        printf("(Enter 'q' to quit payment calculation).\n");
        while ((scanf("%f", &hr)) == 1)
        {
            if (hr <= 0)                        // gross pay calculation
            {   
                printf("Invalid input. Please re-enter:\n");
                continue;
            }   
            else if (hr <= B_HR) 
                gpay = hr * b_rate;                                
            else
                gpay = B_HR * b_rate + (hr - B_HR) * OT_RATE;

            if (gpay <= T_LVL1)                 // tax calculation
                tax = gpay * T_RATE1;
            else if (gpay > T_LVL1 && gpay <= T_LVL2)
                tax = T_LVL1 * T_RATE1 + (gpay - T_LVL1) * T_RATE2;
            else
                tax = T_LVL1 * T_RATE1 + T_LVL2 * T_RATE2 + (gpay - T_LVL1 - T_LVL2) * T_RATE3;
            
            npay = gpay - tax;                  // net pay calculation
            printf("gross pay:%5.2f taxes:%5.2f net pay:%5.2f\n", gpay, tax, npay);
            printf("*****************************************************************\n");
            printf("Enter the next number of hours worked(basic rate remains unchanged): \n");
            printf("(Enter 'q' to quit payment calculation).\n");
        }
        scanf("%*s");                           //clear invalid input "q" from the input buffer
        printf("Enter an integer(1~4) to specify the basic rate or (5) to quit: \n");
    }

    return 0;
}