#include <stdio.h>

int main()
{
    int guess;
    int number = 7, win = 0;
    printf("I have chosen a number between 1 to 10. Try to guess it!\n");

    while (!win)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == number)
            win = 1;
        else 
            printf("That is incorrect. Guess again.\n");
    }
    printf("That's right, you guessed it!!!");

    return 0;
}