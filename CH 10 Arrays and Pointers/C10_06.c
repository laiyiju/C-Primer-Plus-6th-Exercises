// 6. Write a function that reverses the contents of an array of double and test it in a simple
//    program.

#include<stdio.h>
#define LEN 5

void reverse(double ar[], int n);
void display(double ar[], int n);
int main(void)
{
    double ar[LEN] = {1.1, 2.2, 3.3, 4.4, 5.5};  // initialize the array
    int i;
    
    display(ar, LEN);    // array before reverse
    reverse(ar, LEN);    // reverse the array
    display(ar, LEN);    // array after reverse

    return 0;
}

void display(double ar[], int n)   // function to print an array
{
    int i;
    printf("The array:");
    for (i = 0; i < n; i++)
        printf(" %g ", ar[i]);
    printf("\n");
}

void reverse(double ar[], int n)
{
    double temp;

    for (int i = 0; i * 2 < n; i++){
        // swap elements whose indexes add up to (n-1)
        temp = ar[n-i-1];
        ar[n-i-1] = ar[i];
        ar[i] = temp;
    }
}