// 2. Devise a function chline(ch,i,j) that prints the requested character in columns i
//    through j. Test it in a simple driver.

#include<stdio.h>

void chline(char, int, int);
int main(void)
{
    char ch;
    int i, j;

    printf("Enter a printable character:\n");      // read character
    while ((ch = getchar()) <= 32)     // if the input is ASCII unprintable characters
        printf("Your input is not printable. Please try re-enter:\n");
    
    printf("Enter the No. of the starting and ending column separated by a space:\n"); 
    while ((scanf("%d %d", &i, &j)) != 2)
        printf("Invalid input. Please try re-enter:\n");
    
    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    int n;
    for (n = 1; n < i; n++)          // spaces before the designated columns
        printf(" ");
    for (n = 0; n <= j - i; n++)      // designated columns
        putchar(ch);
}