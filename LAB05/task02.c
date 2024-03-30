#include <stdio.h>

int main()
{
    printf("\nX\tFactorial of X");

    int i = 1;
    while (i <= 5)
    {
        int factorial = 1;
        int j = 1;
        while (j <= i)
        {
            factorial *= j;
            j++;
        }
        printf("\n%d\t\t%d", i, factorial);
        i ++;
    }
    return 0;
}