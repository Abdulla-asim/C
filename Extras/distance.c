#include <stdio.h>

void main()
{
    float distance;

    printf("Enter the distance (km): ");
    scanf("%f", &distance);

    printf("\nThe distance in metres is: %.2f", distance * 1000);
    printf("\nThe distance in feet is: %.2f", distance * 3280.84);
    printf("\nThe distance in inches is: %.2f", distance * 39370.1);
    printf("\nThe distance in centimetres is: %.2f\n", distance * 100000);
}
