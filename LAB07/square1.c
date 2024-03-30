#include <stdio.h>

void print_square(int n);

int main()
{
    int n;

    printf("Side: ");
    scanf("%d", &n);

    print_square(n);

    return 0;
}

void print_square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("* ");
    puts("");
    }
}