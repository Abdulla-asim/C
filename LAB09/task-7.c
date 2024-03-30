#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice1, dice2, sum = 0, frequency[11] = {0};
    srand(time(NULL));
    
    for (int i = 0; i < 36000; i++)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        sum = dice1 + dice2;

        frequency[sum - 2]++;
    }

    puts("SUM\tFREQUENCY");
    for (int j = 0; j < 11; j++)
        printf("%2d\t %5d\n", j + 2, frequency[j]);

    return 0;
}