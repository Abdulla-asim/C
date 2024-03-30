#include <stdio.h>
#include <math.h>

double hypotenuse(double x, double y);

int main()
{
    double x, y;
    printf("Enter the 2 sides of triangle: ");
    scanf("%lf %lf", &x, &y);

    hypotenuse(x, y);

    return 0;
}

double hypotenuse(double x, double y)
{
    printf("%lf", sqrt(x*x + y*y));
}