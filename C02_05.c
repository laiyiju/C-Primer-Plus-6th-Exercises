// 5. Write a program that produces the following output:
//       Brazil, Russia, India, China
//       India, China,
//       Brazil, Russia
//    Have the program use two user-defined functions in addition to main(): one named
//    br() that prints “Brazil, Russia” once, and one named ic() that prints “India, China”
//    once. Let main() take care of any additional printing tasks.

#include<stdio.h>

void br(void);
void ic(void);

int main(void)
{
    br();
    printf(", ");
    ic();
    printf("\n");

    ic();
    printf(",\n");

    br();

    return 0;
}

void br(void)
{
    printf("Brazil, Russia");
}

void ic(void)
{
    printf("India, China");
}
