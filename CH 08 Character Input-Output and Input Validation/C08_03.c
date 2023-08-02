// 3. Write a program that reads input as a stream of characters until encountering EOF.
//    Have it report the number of uppercase letters, the number of lowercase letters, and the
//    number of other characters in the input. You may assume that the numeric values for the
//    lowercase letters are sequential and assume the same for uppercase. Or, more portably,
//    you can use appropriate classification functions from the ctype.h library.

#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int uct = 0;    // uppercase letters count
    int lct = 0;    // lowercase .............
    int oct = 0;    // other characters ......

    printf("Enter whatever you want and press Ctrl+D to end input:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            uct++;
        else if (islower(ch))
            lct++;
        else
            oct++;
    }
    printf("%d uppercase letters, %d lowercase letters, %d other characters.\n", uct, lct, oct);

    return 0;
}