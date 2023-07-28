// 2. Write a program that reads input until encountering #. Have the program print each
//    input character and its ASCII decimal code. Print eight character-code pairs per line.
//    Suggestion: Use a character count and the modulus operator (%) to print a newline
//    character for every eight cycles of the loop.

#include<stdio.h>
int main(void)
{
    const int PPL = 8;                 // 8 character-code pairs per line
    char ch;
    int char_ct = 0;

    printf("Enter some characters.\n");
    printf("Enter # to quit: \n");
    while ((ch = getchar()) != '#')
    {
        char_ct++;            
        switch (ch)
		{
			case ' ':                               
					printf("  ' ':%-5d", ch);    // print a pair of quotation marks to show
					break;                       // that the input is a space character
			case '\t':
					printf("'\\t':%-5d", ch);  // same as above, so that we can tell which
					break;                       // type of whitespace the input is
			case '\n':
					printf("'\\n':%-5d", ch);  // same as above
					break;
			default:
					printf("%5c:%-5d", ch, ch); // the minus sign means left-aligned
		}
        
        if (char_ct % PPL == 0)                  // add newline every 8 pairs of characters
            printf("\n");
    }
    printf("\nDone.");

    return 0;
}