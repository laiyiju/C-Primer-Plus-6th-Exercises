// 12. Write a program that reads input up to EOF and reports the number of words, the
//     number of uppercase letters, the number of lowercase letters, the number of punctuation
//     characters, and the number of digits. Use the ctype.h family of functions.

#include<stdio.h>
#include<ctype.h>                             // for isspace()
#include<stdbool.h>                           // for bool, true, false

int main(void)
{
    char ch;                                  // read in character
    int words = 0;                            // number of words
    int uppercase = 0;                        // number of uppercase characters
    int lowercase = 0;                        // number of lowercase characters
    int punctuation = 0;                      // number of punctuation marks
    int digits = 0;                           // number of digits
    bool inword = false;                      // == true if c is in a word

    puts("Enter some words(EOF to quit):");   // prompt for input
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && !inword)
        {
            words++;                          // count word
            inword = true;                    // == true if c is in a word
        }
        if (isspace(ch) && inword)
            inword = false;
        if (isupper(ch))
            uppercase++;
        else if (islower(ch))
            lowercase++;
        else if (ispunct(ch))
            punctuation++;
        else if (isdigit(ch))
            digits++;
    }
    printf("words:%d, uppercase letters:%d, lowercase letters:%d, ", words, uppercase, lowercase);
    printf("punctuation characters:%d, digits:%d.", punctuation, digits);

    return 0;
}