#include <stdio.h>
#include <math.h>

int main()
{
    double num;

    printf("Number: ");
    scanf("%lf", &num);

    int round = floor (num + 0.5);

    printf("%lf rounded is %d\n", num, round);
} 