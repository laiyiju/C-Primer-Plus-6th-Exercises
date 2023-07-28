// 7. Write a program that reads a single word into a character array and then prints the word
//    backward. Hint: Use strlen() ( Chapter 4) to compute the index of the last character in
//    the array.

#include<stdio.h>
#include<string.h>
int main(void)
{
    int i;                 // i as a counter
    char word[20];         // array for a word

    printf("Enter a word: ");
    scanf("%s", &word);

    for (i = strlen(word) - 1; i >= 0; i--)
        printf("%c", word[i]);

    return 0;
}