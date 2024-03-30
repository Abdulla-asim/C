#include <stdio.h>

int main()
{
    // Prints the insides of the diamond.

    for (int i = 1; i <= 5; i++) // Iteration for the upper half (5 rows)
    {
        for (int s = 0; s < 5 - i; s++) // Prints the top left asterisk triangle 
            printf("* ");

        for (int c = 1; c <= i-1; c++) // Prints the left counting (col-1 to col-5) (starting from 1 to 1.2.3.4.5)
            printf("%d ", c);

        for (int c2 = 0; c2 < i; c2++) // Prints the right counting (col-6 to col-9) (starting from 1 in the second row to 4.3.2.1)
            printf("%d ", i-c2);

        for (int s2 = 0; s2 < 5 - i; s2++) // Prints the top right asterisk triangle
            printf("* ");

        printf("\n");
        
    }   

    for (int i = 1; i <= 4; i++) // Iterates for the lower half (4 rows)
    {
        for (int s = 0; s < i; s++) // Prints the bottom left asterisk triangle
            printf("* ");

        for (int c = 1; c <= 5 - i; c++) // Prints the bottom left counting (col-2 to col-5) (1.2.3.4 to 1)
            printf("%d ", c);

        for (int w = 0; w < 4 - i; w++) // Prints the bottom right spaces triangle (col-6 to col-8)
            printf("  ");

        for (int s2 = 0; s2 < i; s2++) // Prints the bottom right asterisk triangle
            printf("* ");

        printf("\n"); // Goes to the next line.
    }
    
    return 0;
}