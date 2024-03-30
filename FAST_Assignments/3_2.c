#include <stdio.h>

int main()
{
    for (int i = 1; i <= 24; i++)
    {
        for (int j = 8; j >= i; j--)
        {
            printf("  ");
        }

        if (i > 16 && i <= 24)
        {
            for (int j = 0; j < i - 16; j++)
                printf("  ");
        }
        if (!(i % 2) )
            printf("-");
        else
            printf("*");
        
        if ((i > 2) && (i < 23) && (i % 2))
                printf("   -");
        else if ((i > 2) && (i < 23) && !(i % 2))
            printf("   *");
        
        
        puts("");
    }
    return 0;
}