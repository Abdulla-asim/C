#include <stdio.h>

int main()
{   
    int s = 25;
    int s2 = 0;

    for (int i = 0; i < 16; i++)
    {
        for (int j = s; j > 0; j--) // First set of spaces before the asterisks
            printf(" "); // Prints the first set of spaces before the asterisks
        s -= 5;

        for (int c = 0; c < 5; c++) // Asterisks that make up the horizontal step
            printf("*");

        for ()




    
        for (int k = s2; k > 0; k--) // Second set of spaces
            printf(" ");
        s2 += 5;

        printf("*"); // Closing asterisk
        printf("\n"); // New line

    }
}