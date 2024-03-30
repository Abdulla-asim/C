#include <stdio.h>

int is_prime(int n);

int main()
{
    int count = 0, true;

    for (int i = 1000; i <= 9999; i++)
    {    
        if (is_prime(i))
        {
            printf("%d is prime\t\t  ", i);
            count++;
        }
    }
    printf("\n\nCount = %d", count);

    return 0;
}

int is_prime(int num)
{
    int factors = 0;
    for (int i = 2; i < num/2; i++)
    {
        if (!(num % i)) // Gives "true" if the num is divisible by "i"
           return 0;
    }
    
    return 1;
}