#include <stdio.h>

int is_perfect(int num);
void display_sum(int n);

int main()
{
    int count = 0;

    for (int i = 1; i <= 1000; i++)
    {
        if (is_perfect(i))
        {
            printf("%d is a perfect number\n", i);
            display_sum(i);
            puts("");
            count++;
        }
        
    }
    printf("\nCount = %d", count);

    return 0;
}

int is_perfect(int num)
{
    int sum = 0;

    for (int i = 1; i < num; i++)
    {
        if (!(num % i))
        {
            sum += i;
        }
    }
    if (sum == num)
        return 1;
    
    return 0;
}

void display_sum(int n)
{
    int sum = 0;
    printf("Sum of: ");

    for (int i = 1; i < n; i++)
    {   
        if (!(n % i))
        {
            sum += i;
            printf("%d, ", i);
        }
    }
    printf("is : %d\n", sum);
}