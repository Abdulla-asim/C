#include <stdio.h>

int main()
{
    int count = 0, numbers[1000];

    for (int x = 0; x < 1000; x++)
        numbers[x] = 1;

    for (int i = 2; i < 1000; i++)
        for (int j = i; j < 1000; j++)
            if (!(j % i) && j != i) numbers[j] = 0;

    for (int k = 2; k < 1000; k++)
        if (numbers[k] == 1) 
        {
            printf("%d is a prime number.\n", k);
            count++;
        }
    printf("\nA total of %d prime numbers were found.", count);

    return 0;
}