#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int guess, random;
    char flag = 'y';

    do
    {
        random = rand() % 1000 + 1;
        printf("I have a number between 1 and 1000. \nCan you guess my number? \nPlease type your first guess : ");
        scanf("%d", &guess);

        while (1)
        {
            if (guess == random) 
            {
                printf("Excellent you guessed the number!!\nWould you like to try again (y or n)? ");
                scanf(" %c", flag);
                break;
            }
            else if (guess < random) printf("Too Low. Try again!");
            else printf("Too high. Try again!");

            printf("\n?");
            scanf("%d", &guess);
        }
        
    }
    while (flag == 'y' || flag == 'Y');

    return 0;
}