#include <stdio.h>

int found(int num, int iterations);

int numbers[20];
int main()
{
    int input, count = 0;

    for (int i = 0; i < 20; i++)
        {
            do{
                printf("Enter a number between 10 to 100: "); // User input.
                scanf("%d", &input);
            } while (input < 10 || input > 100); // Keeps prompting for correct input (between 10 tp 100).

            if (!found(input, i))
            {
                numbers[count] = input;
                count++;
            }
        }
    
    puts("The non duplicate values are:");
    for (int j = 0; j < count; j++)
        printf("%d\t", numbers[j]);

    return 0;
}

int found(int num, int iterations)
{
    for (int i = 0; i <= iterations; i++)
        if (num == numbers[i]) return 1;

    return 0; 
}