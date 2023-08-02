// 5. Modify the guessing program of Listing 8.4 so that it uses a more intelligent guessing
//    strategy. For example, have the program initially guess 50, and have it ask the user
//    whether the guess is high, low, or correct. If, say, the guess is low, have the next guess
//    be halfway between 50 and 100, that is, 75. If that guess is high, let the next guess be
//    halfway between 75 and 50, and so on. Using this binary search strategy, the program
//    quickly zeros in on the correct answer, at least if the user does not cheat.

#include<stdio.h>
int main(void)
{
    int high = 100;
    int low = 1;
    int guess = 50;
    char ch;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right, an h if");
    printf("\nit is high and a l if it is low.\n");
    printf("Uh...is your number %d? \n", guess);
    while ((ch = getchar()) != 'y')        // get response, compare to y
    {
        while (getchar() != '\n')          // dispose of invalid input
            continue;

        if (ch == 'h')
            high = guess - 1;              // raise the lower limit
        else if (ch == 'l')
            low = guess + 1;               // reduce the upper limit
        else
        {
            printf("Invalid input. Enter either h or l:\n");
            continue;
        }
        guess = (high + low) / 2;  

        // If the number returns to a previous position and the user still responds with "h" or 
        // "l", it indicates that the user's reply is mistaken, and a restart is necessary:
        if (guess == high + 1 || guess == low - 1)
        {
            printf("The number returns to %d.\n", guess);    // a number that appears again 
            printf("You either gave me wrong prompts, or you're lying.\n");
            printf("Let's start it all over again.\n");
            printf("Is your number 50?\n");
            high = 100;          // reinitialization
            low = 1; 		 // ...
            guess = 50;		 // ...
            continue;
        }             
	    printf("Well, then, is it %d?\n", guess);
    }
    printf("I knew I could do it!\n");

    return 0;
}
