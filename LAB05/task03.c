#include <stdio.h>

int main()
{
    int d1, d2, d3, d4, result;

    int i = 1000;
    while (i < 10000)
    {
        d1 = i / 1000;
        d2 = (i % 1000) / 100;
        d3 = (i % 100) / 10;
        d4 = (i % 10);

        result = (d1*d1*d1*d1) + (d2*d2*d2*d2) + (d3*d3*d3*d3) + (d4*d4*d4*d4);

        if (result == i)
            printf("%d is an armstrong number.\n", result);

        i++;
    }
    return 0;
}