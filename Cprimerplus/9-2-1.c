#include <stdio.h>

int max();

int  main(void)
{
    printf("The maximum of %d and %d is %d.\n", 3, 5, max(3, 5.0, 100.5));
    printf("The maximum of %d and %d and %d is %d.\n", 3, 5, 7,  max(3, 5, 7));
}


//int max(a, b)
//int a, b;
//{
//    return (a > b) ? a : b;
//}

int max(a, b, c)
int a, b, c;
{
    return (a > b) ? ( (a>c)? a : c) : ((b > c) ? b : c);
}