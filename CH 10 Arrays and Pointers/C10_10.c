// 10. Write a function that sets each element in an array to the sum of the corresponding
//     elements in two other arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2
//     has the values 1, 0, 4, and 6, the function assigns array 3 the values 3, 4, 9, and 14. The
//     function should take three array names and an array size as arguments. Test the function
//     in a simple program.

#include<stdio.h>
#define LEN 4

void display(int ar[], int len);         // declaration
void sum_ar(int ar1[], int ar2[], int sum_ar[], int len);
int main(void)
{
    int array1[LEN] = {2,4,5,8};         // initialization
    int array2[LEN] = {1,0,4,6};
    int array3[LEN];

    printf("two arrays:\n");             // display
    display(array1, LEN);
    display(array2, LEN);
    sum_ar(array1, array2, array3, LEN); // calculation
    printf("array of their elements' sums:\n");
    display(array3, LEN);

    return 0;
}

void display(int ar[], int len)
{
    printf("{");
    for (int i = 0; i < len; i++)
        printf(" %d ", ar[i]);
    printf("}\n");
}

void sum_ar(int ar1[], int ar2[], int ar3[], int len)
{
    for (int i = 0; i < len; i++)
        ar3[i] = ar1[i] + ar2[i];
}