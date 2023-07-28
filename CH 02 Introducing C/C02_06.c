// 6. Write a program that creates an integer variable called toes. Have the program set toes
//    to 10. Also have the program calculate what twice toes is and what toes squared is. The
//    program should print all three values, identifying them.

#include<stdio.h>
int main(void)
{
    int toes, twice, squared;
    toes = 10;
    twice = toes * 2;
    squared = toes * toes;
    printf("toes = %d\ntwice toes = %d\nsquared toes = %d\n",toes, twice, squared);

    return 0;
}
