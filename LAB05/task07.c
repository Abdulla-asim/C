#include <stdio.h>

int main()
{
    int num = 2;
    while (num <= 10000)
    {
        int counter = 1;
        int divisor = 0;
        while (counter <= num)
        {
            if (!(num % counter))
                divisor++;

            if (divisor > 2)
                break;

            counter++;
        }
        if (divisor <= 2)
            printf("%d is a prime number\t\t  ", num);
        
        
        num++;
    }
    return 0;
}