// 4. Write a function that returns the index of the largest value stored in an array-of-double.
//    Test the function in a simple program.

#include<stdio.h>
int max(int arr[], int n);
int main(void)
{
    int nums[10] = {99,34,45,28,89,85,1,5,72,200};
    int i;

    printf("The elements of the array:\n");
    for (i = 0; i < 10; i++)
        printf(" %d ", nums[i]);
    printf("\nThe index of the largest value is %d", max(nums, 10));

    return 0;
}

int max(int arr[], int n)
{
    int max_index = 0;

    for (int i = 1; i < n; i++)            // compare the elements one by one
        if (*(arr + max_index) < arr[i])   
            max_index = i;                 // store the larger element's index

    return max_index;
}