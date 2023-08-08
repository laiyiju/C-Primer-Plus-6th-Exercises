// 11. Write and test a Fibonacci() function that uses a loop instead of recursion to calculate
//     Fibonacci numbers.

#include<stdio.h>

long Fibonacci(unsigned);      
int main(void)
{
    int n;

    printf("Enter an integer.\n");
    while (scanf("%u", &n) == 1 && n > 0)
    {
        printf("The Fibonacci number at the designated location is %ld.\n", 
                Fibonacci(n));
        printf("Enter next number:\n");
    }
    printf("Done.\n");

    return 0;
}

// if using type int for fibonacci number, n can only reach a maximum of 46.
// if using long int, n can reach a maximum of 103 before the return value 
// turns negative.
long Fibonacci(unsigned n)     
{
    long fibo;   // fibonacci number
    long n1, n2;  // 2 preceding numbers
    n1 = n2 = 1; // initialization

    if (n == 1 || n == 2)
        return 1;
    
    // i as a loop counter is declared and defined 
    // within the initialization part of the loop.
    for (int i = 2; i < n; i++)   // 'int' is necessary for declaration
    {
        fibo = n1 + n2;
        n1 = n2;
        n2 = fibo;
    }
    return fibo;
}