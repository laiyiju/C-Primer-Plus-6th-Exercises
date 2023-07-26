// 2. Use nested loops to produce the following pattern:
//    $
//    $$
//    $$$
//    $$$$
//    $$$$$

#include<stdio.h>
#define ROW 5         // number of rows
#define COL 5         // number of columns
int main(void)
{
    int n, m;         // for counting
    char ch = '$';    // characters to be printed
    for (n = 0; n < ROW; n++){
        for (m = 0; m <= n; m++){
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}