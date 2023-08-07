// 10. Generalize the to_binary() function of Listing 9.8 to a to_base_n() function that
//     takes a second argument in the range 2–10. It then should print the number that is its
//     first argument to the number base given by the second argument. For example, to_
//     base_n(129,8) would display 201, the base-8 equivalent of 129. Test the function in a
//     complete program.

#include<stdio.h>
void to_base_n(int, int);
int main(void)
{
    int dnum;   // a decimal number
    int n;      // base n
    
    printf("Enter a decimal integer and a base number(q to quit):\n");
    while (scanf("%d%d", &dnum, &n) == 2)
    {
        if (n < 2 || n > 10)
        {
            printf("base must be between 2 and 10.\n");
            printf("Enter the integer and a new base number:\n");
            continue;
        }
        printf("The base %d equivalent of %d is: ", n, dnum);
        to_base_n(dnum, n);
        printf("\nEnter the next integer:\n");
    }

    return 0;
}

void to_base_n(int dnum, int n)
{

    if (dnum >= n)                  // if dnum < n, the quotient is 0
	    to_base_n(dnum / n, n);     // calculate the quotient
    printf("%d", dnum % n);         // calculate the remainder 
}