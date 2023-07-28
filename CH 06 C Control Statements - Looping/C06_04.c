// 4. Use nested loops to produce the following pattern:
//       A
//       BC
//       DEF
//       GHIJ
//       KLMNO
//       PQRSTU
//    If your system doesn’t encode letters in numeric order, see the suggestion in
//    programming exercise 3.
#include<stdio.h>
#define ROW 6
#define COL 6
int main(void)
{
    int n,m;
    char ch = 'A';

    for (n = 0; n < ROW; n++)
    {
        for (m = 0; m <= n; m++, ch++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    
    return 0;
}