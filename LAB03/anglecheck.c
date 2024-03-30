#include <stdio.h> // Abdullah, 455340

void main()
{
    float a, b, c;

    printf("Enter the three angles of a triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b + c == 180)
        printf("Congratulations! It is a valid triangle.\n");
    else 
        printf("Sorry! It is not a valid triangle.\n");
}