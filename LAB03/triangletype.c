#include <stdio.h>

// Funtion prototypes
int scalene(int a, int b, int c);
int equilateral(int a, int b, int c);
int right(int n1, int n2, int n3);
int isosceles(int a, int b, int c);

void main()
{
    int a, b, c;

    printf("Enter the three sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);

// Print the type of triangle
    if (scalene(a, b, c))
        printf("It is a scalene triangle.\n");
    if (equilateral(a, b, c))
        printf("It is an equilateral triangle.\n");
    if (right(a, b, c))
        printf("It is a right triangle.\n");
    if (isosceles(a, b, c))
        printf("It is an isosceles triangle.\n");
}

// Checks for scalene triangle
int scalene(int a, int b, int c)
{
    if ((a != b) && (a != c))
        return 1;

    return 0;
}

// Checks for equilateral triangle
int equilateral(int a, int b, int c)
{
    if (a == b && a == c)
        return 1;
    
    return 0;
}

// Chekc for right triangle
int right(int n1, int n2, int n3)
{
    // Checks if the sides can be the sides of a right triangle and prints the answer.
    if ((n1*n1 == n2*n2 + n3*n3) || (n2*n2 == n3*n3 + n1*n1) || (n3*n3 == n1*n1 + n2*n2))
        return 1;

    return 0;
}

// Check for isosceles triangle
int isosceles(int a, int b, int c)
{
    if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
        return 1;
    
    return 0;
}