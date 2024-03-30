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

    int reverse = (d5*10000) + (d4*1000) + (d3*100) + (d2*10) + (d1);
    printf("\nThe reverse of %d is %d.\n\n", num, reverse);
}