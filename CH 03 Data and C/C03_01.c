// 1. Find out what your system does with integer overflow, floating-point overflow, and
//    floating-point underflow by using the experimental approach; that is, write programs
//    having these problems. (You can check the discussion in Chapter 4 of limits.h and
//    float.h to get guidance on the largest and smallest values.)

#include<stdio.h>
int main(void)
{
    int max_int = 2147483647;
    float max_float = 3.4028235e38;
    float min_float = 1.4012985e-45;

    printf("integer overflow leads to the result: %d\n", max_int + 1);
    printf("floating-point overflow leads to the result: %f\n", max_float * 10);
    printf("floating-point underflow leads to the result: %f\n", min_float / 10);

    return 0;
}
