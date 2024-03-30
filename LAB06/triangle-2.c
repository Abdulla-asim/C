#include <stdio.h>

int main()
{
    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            printf("* ");
        puts("");
    }

    return 0;
}