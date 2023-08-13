// 3. Write a function that returns the largest value stored in an array-of-int. Test the function
//    in a simple program.

#include<stdio.h>
int max(int arr[], int n);
int main(void)
{
    int nums[10] = {99,34,45,28,89,85,1,5,72,200};
    int i;

    printf("The elements of the array:\n");
    for (i = 0; i < 10; i++)
        printf(" %d ", nums[i]);
    printf("\nThe largerst value of the array is %d", max(nums, 10));

    return 0;
}

int max(int arr[], int n)
{
    int i = 0;
    int max = arr[i];
    
    for (i = 1; i < n; i++)     // compare the elements one by one
        if (arr[i] > max)       // assign the larger value to max
            max = arr[i];

    return max;
}
