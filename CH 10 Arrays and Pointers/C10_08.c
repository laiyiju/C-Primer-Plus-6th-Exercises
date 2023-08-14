// 8. Use a copy function from Programming Exercise 2 to copy the third through fifth
//    elements of a seven-element array into a three-element array. The function itself need
//    not be altered; just choose the right actual arguments. (The actual arguments need not be
//    an array name and array size. They only have to be the address of an array element and a
//    number of elements to be processed.)

#include<stdio.h>
#define LEN_SO 7
#define LEN_TA 3

void display(int ar[], int n);
void extract35(int tar[], const int sou[], int n);  // use 'const' to protect original array
int main(void)
{
    int source[LEN_SO] = {1,2,3,4,5,6,7};       // initialize source array
    int target[LEN_TA];

    printf("The source array: ");               // display source array
    display(source, LEN_SO);
    extract35(target, source + 2, LEN_TA);      // extract 3 elements
    printf("The target array: ");
    display(target, LEN_TA);                    // display target array

    return 0;
}

void display(int ar[], int n)                   
{
    for (int i = 0; i < n; i++)
        printf(" %d ", ar[i]);
    printf("\n");
}

void extract35(int tar[], const int sou[], int n)      
{   // ptr must also be declared as constant, otherwise you cannot
    // assign const int array 'sou' to an int *ptr.
    for (const int *ptr = sou; ptr < sou + n; ptr++, tar++) 
        *tar = *ptr;
}