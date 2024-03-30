#include <stdio.h>

void main()
{
    int r;
    float pi = 3.14159;

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    printf("\nThe diameter is: %d", r * 2);
    printf("\nThe circumference is: %f", 2 * pi * r);
    printf("\nThe area is: %f\n", pi * r * r);

}