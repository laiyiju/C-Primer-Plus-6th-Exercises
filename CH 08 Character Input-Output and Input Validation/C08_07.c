// 7. Modify Programming Exercise 8 from Chapter 7 so that the menu choices are labeled by
//    characters instead of by numbers; use q instead of 5 as the cue to terminate input.

#include<stdio.h>
#include<ctype.h>
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

void menu(void);
int get_first(void);
int main(void)
{
    float hr, b_rate, gpay, tax, npay;
    int choice;
    
    menu();

    while ((choice = get_first()) != 'q')                    
    {
        choice = tolower(choice);                 // accept A as a, etc.
        if (choice >= 'a' && choice <= 'd')       // choose a basic rate
            switch (choice)                         
            {
                case 'a': b_rate = BR1;           // replace numbers by characters 
                          break;
                case 'b': b_rate = BR2;
                          break;
                case 'c': b_rate = BR3;
                          break;
                case 'd': b_rate = BR4;
                          break;
            }
        else                                     // require a proper input
        {
            printf("Invalid input. Please enter an integer from a through d:\n");
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
        printf("Enter an integer(1~4) to specify the basic rate\n");
        printf("or (5) to quit the program: \n");
    }
    printf("Done.\n");

    return 0;
}

void menu(void)
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $%5.2f/hr                   b) $%5.2f/hr\n", BR1, BR2);
    printf("c) $%5.2f/hr                   d) $%5.2f/hr\n", BR3, BR4);
    printf("q) quit\n");
    printf("*****************************************************************\n");
}

int get_first(void)
{
    int ch;

    ch = getchar();                  
    while (isspace(ch))         // dispose of space characters
        ch = getchar();
    while (getchar() != '\n')   
        continue;

    return ch;
}