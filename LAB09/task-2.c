#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int input, count = 0, array[25];

    srand(time(NULL));

    for (int i = 0; i < 25; i++)
        array[i] = rand() % 10 + 1; // Stores random numbers from 1 to 10 in the array.

    printf("Enter the number to be searched: ");
    scanf("%d", &input);
    for (int j = 0; j < 25; j++)
        if (array[j] == input) count++;

    if (count > 0)
        printf("\n%d is found %d times in the array...", input, count);
    else
        printf("\n%d is not found in the array...");

    return 0;
}