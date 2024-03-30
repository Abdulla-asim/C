#include <stdio.h>

void main()
{
    int a, b, c, sum;

    printf("Enter the numbers(with spaces): ");
    scanf("%d %d %d", &a, &b, &c);

    sum = a + b + c;

    printf("\nThe sum is: %d", sum);
    printf("\nThe average is: %f", sum / 3.0);
    printf("\nThe product is: %d \n", a*b*c);

}