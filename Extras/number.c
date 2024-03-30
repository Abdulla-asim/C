#include <stdio.h>

void main()
{
    int num, d1, d2, d3, d4, d5;

    printf("Enter a 5-digit number: ");
    scanf("%d", &num);

    d1 = num /10000;
    d2 = (num % 10000) / 1000;
    d3 = (num % 1000) / 100;
    d4 = (num % 100) / 10;
    d5 = num % 10;

    printf("\n%d   %d   %d   %d   %d\n\n", d1, d2, d3, d4, d5);
}