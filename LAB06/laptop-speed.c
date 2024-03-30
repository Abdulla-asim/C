#include <stdio.h>

int main()
{
    for (int i = 1; i <= 300000000; i++)
    {
        if (i == 100000000)
            puts("Multiple is 1.");
        else if (i == 200000000) 
            puts("Multiple is 2.");
        else if (i == 300000000)
            puts("Multiple is 3.");        
    }
}