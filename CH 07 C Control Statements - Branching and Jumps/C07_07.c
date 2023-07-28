// 7. Write a program that requests the hours worked in a week and then prints the gross pay,
//    the taxes, and the net pay. Assume the following:
//        a. Basic pay rate = $10.00/hr
//        b. Overtime (in excess of 40 hours) = time and a half
//        c. Tax rate: #15% of the first $300
//        20% of the next $150
//        25% of the rest
//    Use #define constants, and don’t worry if the example does not conform to current
//    tax law.

#include<stdio.h>
#define P_RATE 10.00          // basic pay rate
#define OT_RATE 15.00         // overtime pay rate
#define B_HR 40               // basic work hours
#define T_RATE1 0.15          // tax rate of first $300
#define T_RATE2 0.20          // tax rate of the next $150
#define T_RATE3 0.25          // tax rate of the rest
#define T_LVL1 300.00
#define T_LVL2 450.00

int main(void)
{
    float hr, gpay, tax, npay;

    printf("Enter the hours worked in a week(enter 'q' to quit): \n");
    while ((scanf("%f", &hr)) == 1)
    {
        if (hr <= 0)                                             // gross pay calculation
        {   
            printf("Invalid input. Please re-enter:\n");
            continue;
        }   
        else if (hr <= B_HR) 
            gpay = hr * P_RATE;                                
        else
            gpay = B_HR * P_RATE + (hr - B_HR) * OT_RATE;

        if (gpay <= T_LVL1)                                     // tax calculation
            tax = gpay * T_RATE1;
        else if (gpay > T_LVL1 && gpay <= T_LVL2)
            tax = T_LVL1 * T_RATE1 + (gpay - T_LVL1) * T_RATE2;
        else
            tax = T_LVL1 * T_RATE1 + T_LVL2 * T_RATE2 + (gpay - T_LVL1 - T_LVL2) * T_RATE3;
        
        npay = gpay - tax;                                      // net pay calculation
        printf("gross pay:%5.2f taxes:%5.2f net pay:%5.2f\n", gpay, tax, npay);
        printf("Enter the next number of hours worked: \n");
    }
    
    return 0;
}