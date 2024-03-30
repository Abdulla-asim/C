#include <stdio.h>
#include <math.h>
// Function Prototypes
double ceiling(double x); 
double flooring(double x);

int main()
{
    double num;
    int choice;

    printf("Number: "); // Input the number to be floored or ceiled
    scanf("%lf", &num);

    printf("1. Floor\n2. Ceil\n\nInput (1 or 2): "); // Asking useer to enter their choice
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nNumber: %lf\t\tFloor = %lf\n\n", num, flooring(num)); // Floors the number
            break;
        case 2:
            printf("\nNumber: %lf\t\tCeil = %lf\n\n", num, ceiling(num)); // Ceils the number
            break;
    }
}

double ceiling(double x) // Ceiling function
{
    return ceil(x);
}

double flooring(double x) // Flooring function 
{
    return floor(x);
}