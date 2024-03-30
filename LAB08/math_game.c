#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int ans, rand1, rand2;

    printf("Enter -1 to end. \n\n");

    while(1)
    {
        rand1 = rand() % 9;
        rand2 = rand() % 9;

        printf("What is %d times %d ? ", rand1, rand2);
        scanf("%d", &ans);

        if (ans == -1) 
        {
            printf("That's all for now. Bye!!\n\n");
            break;
        }
        else if (ans == rand1 * rand2) printf("Very Good!\n");
        else
        {
            printf("NO. Please try again. . .\n");
            do
            {
                printf("? ");
                scanf("%d", &ans);
            }
            while (ans != rand1 * rand2);
        }
    }
    return 0;
}