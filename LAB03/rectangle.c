#include <stdio.h> // Abdullah, 455340

void main()
{
    int x, y;

    printf("Enter the length and width of a rectangle: ");
    scanf("%d %d", &x, &y);

// Calculates the area and perimeter.
    int A = x * y;
    int P = x*2 + y*2;

// Prints the area and perimeter of the rectangle
    printf("Area: %d\nPerimeter: %d\n", A, P);

// Compares the area and the perimeter of the rectangle.    
    if (A > P)
        printf("The area of this rectangle is greater than its perimeter.\n");
    else if (A == P)
        printf("The area of this rectangle is equal to its perimeter.\n");
    else
        printf("The area of this rectangle is less than its perimeter.\n");
}