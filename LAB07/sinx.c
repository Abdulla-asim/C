#include <stdio.h>

int factorial(int n);
double power(double x, int n);
double sin_x(double x, int terms);

int main()
{
    int terms = 8; //Change to get more terms.
    double x;

    printf("Enter the angle for sin(x): ");
    scanf("%lf", &x);

    printf("sin(x) = %lf", sin_x(x, terms));

    return 0;
}

double sin_x(double x, int terms)
{
    double sin = 0;
    int odd = 1;

    for (int i = 1; i <= terms; i++)
    {
        if (i % 2)
            sin += power(x, odd) / (float) factorial(odd);
        else   
            sin -= power(x, odd) / (float) factorial(odd);

        odd += 2;
    }

    return sin;
}

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double power(double x, int n)
{
    float result = 1;
    
    for (int i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}
