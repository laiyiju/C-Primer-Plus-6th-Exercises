// 5. Have a program request the user to enter an uppercase letter. Use nested loops to produce
//    a pyramid pattern like this:
//          A
//         ABA
//        ABCBA
//       ABCDCBA
//      ABCDEDCBA
//    The pattern should extend to the character entered. For example, the preceding pattern
//    would result from an input value of E. Hint: Use an outer loop to handle the rows. Use
//    three inner loops in a row, one to handle the spaces, one for printing letters in ascending
//    order, and one for printing letters in descending order. If your system doesn’t use ASCII
//    or a similar system that represents letters in strict number order, see the suggestion in
//    programming exercise 3.

#include<stdio.h>
int main(void)
{
    char ch1, ch2;                    // ch1: the goal char, ch2: the control char for printing
    int row, space;
    
    printf("Enter a uppercase character: ");
    scanf("%c", &ch1);

    for (row = 0; row < ch1 - 'A' + 1; row++)
    {
        for (space = 0; space < ch1 - 'A' - row; space++)
            printf(" ");
        for (ch2 = 'A'; ch2 <= 'A' + row; ch2++)
            printf("%c", ch2);
        for (ch2 = 'A' + row -1; ch2 >= 'A'; ch2--)
            printf("%c", ch2);
        printf("\n");
    }

    return 0;
}