#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        int spaces = 9;
        for (int j = 0; j < 10; j++)
        {
            if (i < spaces)
                printf("  ");
            else 
                printf("* ");

            spaces--;
        }
        puts("");

    }
}