// A Program to check if a number is even or odd or zero.
#include <stdio.h> // Abdullah, 455340

void main()
{
    int a;

    printf("Enter a number to be checked: ");
    scanf("%d", &a);

    if (a == 0)
        printf("Zero is Neither even nor odd.\n");
    else if (a % 2 == 0)
        printf("Even.\n");
    else
        printf("Odd.\n");
}

