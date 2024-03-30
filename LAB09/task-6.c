#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int roll[100], freq[7]; // roll[] size to million to store million dice rolls
    int size = 100; // Change the size to million for a million dice rolls.

    for (int z = 0; z < size; z++) // Initializing arrays to zero.
    {
        roll[z] = 0;
        freq[z] = 0;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        roll[i] = rand() % 6 + 1;

    for (int j = 0; j < size; j++)
        freq[roll[j]]++;

    printf("OUTCOME\tFREQUENCY HSITOGRAM\n");
    for (int l = 1; l <= 6; l++)
    {
        printf("%d\t %6d\t  ", l, freq[l]);
        for (int k = 0; k < freq[l]; k++)
            printf("%s", "*");
        puts("");
    }

    return 0;
}