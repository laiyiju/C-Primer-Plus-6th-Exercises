// 8. Write a program that shows you a menu offering you the choice of addition, subtraction,
//    multiplication, or division. After getting your choice, the program asks for two numbers,
//    then performs the requested operation. The program should accept only the offered
//    menu choices. It should use type float for the numbers and allow the user to try again
//    if he or she fails to enter a number. In the case of division, the program should prompt
//    the user to enter a new value if 0 is entered as the value for the second number. A typical
//    program run should look like this:
//        Enter the operation of your choice:
//        a. add s. subtract
//        m. multiply d. divide
//        q. quit
//        a
//        Enter first number: 22.4
//        Enter second number: one
//        one is not an number.
//        Please enter a number, such as 2.5, -1.78E8, or 3: 1
//        22.4 + 1 = 23.4
//        Enter the operation of your choice:
//        a. add s. subtract
//        m. multiply d. divide
//        q. quit
//        d
//        Enter first number: 18.4
//        Enter second number: 0
//        Enter a number other than 0: 0.2
//        18.4 / 0.2 = 92
//        Enter the operation of your choice:
//        a. add s. subtract
//        m. multiply d. divide
//        q. quit
//        q
//        Bye.

#include<stdio.h>
#include<ctype.h>

void menu(void);
int getfirst(void);
float getnum(void);

int main(void)               
{
    int ch;
    float n1, n2;
    float result;
    char operator;

    menu();
    while ((ch = getfirst()) != 'q')
    {
        printf("Enter first number: ");
        n1 = getnum();
        printf("Enter second number: ");
        n2 = getnum();

        switch(ch)
        {
            case 'a': result = n1 + n2;
                      operator = '+';
                      break;
            case 's': result = n1 - n2;
                      operator = '-';
                      break;
            case 'm': result = n1 * n2;
                      operator = '*';
                      break;
            case 'd': while (n2 == 0)       
                      {
                        printf("Enter a number other than 0: ");
                        n2 = getnum();
                      }
                      result = n1 / n2;
                      operator = '/';                        
                      break;
        }
        printf("%.1f %c %.1f = %.1f\n", n1, operator, n2, result);
        menu();
    }
    printf("Bye.\n");

    return 0;
}

void menu(void)            // a menu of prompt for input
{
    printf("--------------------------------------------\n");
    printf("Enter the operation of your choice:\n");
    printf("a. add          s. subtract\n");
    printf("m. multiply     d. divide\n");
    printf("q. quit\n");
}

int getfirst(void)         // read the first valid character that is not whitespace 
{
    int ch;
    
    do ch = getchar();    
    while (isspace(ch));  // dispose of space characters

    while (getchar() != '\n')
        ;                 // "continue" is intentionally omitted.

    while ((ch != 'a') && (ch != 's') && (ch != 'm') && (ch != 'd') && (ch != 'q'))
    {
        printf("Sorry. Only a,s,m,d,q are accepted.\n");
        printf("Re-enter your choice: \n");
        ch = getchar();
    }

    return ch;
}

float getnum(void)        // read a number for calculation
{
    float num;
    int invalid;

    while (scanf("%f", &num) != 1)
    {
        while ((invalid = getchar()) != '\n')
            putchar(invalid);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    
    return num;
}