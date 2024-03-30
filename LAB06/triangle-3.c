#include <stdio.h>

int main()
{
    //

    for (int i = 10; i > 0; i--)
    {
        int spaces = 10; 

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

    return 0;
}