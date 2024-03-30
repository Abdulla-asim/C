#include <stdio.h>

int is_bouncy(int n);

int main()
{
    int count = 0, true;

    for (int i = 1000; i <= 9999; i++)
    {
        true = is_bouncy(i);
        if (true)
        {
            printf("%d is bouncy\t\t  ", i);
            count++;
        }
        
    }
    printf("\n\nCount = %d", count);

    return 0;
}

int is_bouncy(int n)
{
    int d1 = n / 1000;
    int d2 = (n % 1000) / 100;
    int d3 = (n % 100) / 10;
    int d4 = n % 10;

    if (d1 >= d2 && d2 >= d3 && d3 >= d4 || d1 <= d2 && d2 <= d3 && d3 <= d4)
        return 0;

    return 1;
}