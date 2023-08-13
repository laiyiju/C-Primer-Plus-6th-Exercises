// 2. Write a program that initializes an array-of-double and then copies the contents of the
//    array into three other arrays. (All four arrays should be declared in the main program.) To
//    make the first copy, use a function with array notation. To make the second copy, use a
//    function with pointer notation and pointer incrementing. Have the first two functions
//    take as arguments the name of the target array, the name of the source array, and the
//    number of elements to be copied. Have the third function take as arguments the name
//    of the target, the name of the source, and a pointer to the element following the last
//    element of the source. That is, the function calls would look like this, given the following
//    declarations:
//       double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
//       double target1[5];
//       double target2[5];
//       double target3[5];
//       copy_arr(target1, source, 5);
//       copy_ptr(target2, source, 5);
//
//       copy_ptrs(target3, source, source + 5);

#include<stdio.h>
void copy_arr(double tar[], double sou[], int n);
void copy_ptr(double *tar, double *sou, int n);
void copy_ptrs(double *tar, double *sou, double *fol_sou);  
// fol_sou a pointer to the element following the last element of the source

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    int i;          // index for printing arrays
    
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    // print the 3 copy arrays in 3 columns
    printf("target1  target2  target3\n");  
    for (i = 0; i < 5; i++){
        printf("  %.1f      %.1f      %.1f", 
        target1[i], target2[i], target3[i]);
        printf("\n");
    }

    return 0;
}

// copy function with array notation
void copy_arr(double tar[], double sou[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        tar[i] = sou[i];
}

// copy function with pointer notation and pointer incrementing
void copy_ptr(double *tar, double *sou, int n)
{
    int i;

    for (i = 0; i < n; i++)
        *(tar + i) = *(sou + i);
}

// copy function with pointer notation and the pointer to
// the next element after the end of the array
void copy_ptrs(double *tar, double *sou, double *fol_sou)
{
    for (double *ptr = sou; ptr < fol_sou; tar++, ptr++)
        *tar = *ptr;
}
