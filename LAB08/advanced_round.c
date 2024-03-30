#include <stdio.h>
#include <math.h>

double RoundToInt(double x);
double RoundToTenth(double x);
double RoundToHundred(double x);
double RoundToThousand(double x);

int main()
{
    int count;
    double num;

    printf("How many numbers do you want to process : ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        printf("Number : ");
        scanf("%lf", &num);

        printf("%lf rounded to an integer is: %lf\n", num, RoundToInt(num));
        printf("%lf rounded to the nearest tenth is: %lf\n", num, RoundToTenth(num));
        printf("%lf rounded to neareest hundredth is: %lf\n", num, RoundToHundred(num));
        printf("%lf rounded to the nearest thousandth is: %lf\n", num, RoundToThousand(num));
    }
    return 0;
}

double RoundToInt(double x)
{
    return floor (x + 0.5);
}

double RoundToTenth(double x)
{
    return floor (x * 10 + 0.5) / 10;
}

double RoundToHundred(double x)
{
    return floor (x * 100 + 0.5) / 100;
}

double RoundToThousand(double x)
{
    return floor (x * 1000 + 0.5) / 1000;
}