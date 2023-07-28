// 16. Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
//     an interest equal to 10% of the original investment.) Deirdre invests $100 at 5% interest
//     compounded annually. (That is, interest is 5% of the current balance, including previous
//     addition of interest.) Write a program that finds how many years it takes for the value
//     of Deirdre’s investment to exceed the value of Daphne’s investment. Also show the two
//     values at that time.

#include<stdio.h>
#define in1 0.10f
#define in2 0.05f
int main(void)
{
    int year = 0;
    float Da_ret = 100.0f, De_ret = 100.0f;
    
    while (Da_ret >= De_ret)
    {
        Da_ret += 100.0 * in1;
        De_ret *= 1.0 + in2;
        year++;
    }
    printf("It took %d years for Deirdre's value(%.2f) to exceed Daphne's(%.2f).", year, Da_ret, De_ret);

    return 0;
}