#include <stdio.h>

void main()
{
    s = 25;

    for (int i = 0; i < 5; i ++)
    {
        for (int k = s; k > 0; k++)
        {
            printf(" ");
        }
        s -= 5;
        for (int j = 0; j < 6; j++)
        {
            if ((i != 0)&&(i != 3)&&(i != 6)&&(i != 9)&&(i != 12)&&(i != 15))
            {
                    printf("*");
            }
            
        }
    }
}`