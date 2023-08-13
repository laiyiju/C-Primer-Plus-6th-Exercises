// 5. Write a function that returns the difference between the largest and smallest elements of
//    an array-of-double. Test the function in a simple program.

#include<stdio.h>
#define LEN 10      
double range(const double ar[], int n);// add 'const' to protect the original data
int main(void)
{
    int i;
    double ar[LEN] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,11.0};
    
    printf("Array ar contains: ");     // display the array
    for (i = 0; i < LEN; i++)
        printf(" %.1lf ", ar[i]);

    printf("\nThe difference between the largest and smallest elements\n");
    printf("of ar is %.1lf.", range(ar, LEN));   // display the difference

    return 0;
}

double range(const double ar[], int n)
{
    double max = ar[0];
    double min = ar[0];

    for (int i = 0; i < n; i++){       // declare and initialize i
        if (ar[i] > max) max = ar[i];  // search for the largest
        if (ar[i] < min) min = ar[i];  // search for the smallest
    }

    return max-min;      // return the difference
}