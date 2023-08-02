// 4. Write a program that reads input as a stream of characters until encountering EOF. Have
//    it report the average number of letters per word. Don’t count whitespace as being letters
//    in a word. Actually, punctuation shouldn’t be counted either, but don’t worry about that
//    now. (If you do want to worry about it, consider using the ispunct() function from the
//    ctype.h family.)

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int wct;   // word count
    int lct;   // letter count
    float lpw; // letters per word
    bool inword = false;     

    printf("This is a program to calculate average number of letters per word.\n");
    printf("Enter one or more sentences and press Ctrl+D to end input:\n");
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            lct++;
            if (!inword)         // only when the previous state is not inword
            {
                inword = true;   // switch to inword because a letter was just read
                wct++;           // and count a word
            }                    // if the previous state is already inword, no increment
        }
        else                     // if the input is not a letter, switch inword to false
            inword = false;        
    }
    lpw = (float)lct / (float)wct;       // use type casting to avoid truncation
    printf("there are %.2f letters per word.\n", lpw);

    return 0;
}