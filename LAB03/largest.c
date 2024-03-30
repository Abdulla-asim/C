// Prints the largest and smaller number.
#include <stdio.h> //Abdullah, 455340

void main()
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

//Prints the largest Number
    if (a > b && a >c)
            printf("Largest: %d\n", a);
    if (c > a && c > b)
            printf("Largest: %d\n", c);
    if (b > a && b > c)
            printf("Largest: %d\n", b);

//Prints the smallest number
    if (a < b && a < c)
        printf("Smallest: %d\n", a);
    if (b < a && b < c)
        printf("Smallest: %d\n", b);
    if (c < a && c < b)
        printf("Smallest: %d\n", c);
}
