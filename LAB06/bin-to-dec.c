#include <stdio.h>

int main()
{
    long int binary;
    int bin, decimal = 0, n = 1;

    do
    {
        bin = 1; // flag

        printf("Enter a binary number: ");
        scanf("%ld", &binary);

        int num = binary;

        while (num != 0) 
        {
            if (num % 10 != 0 && num % 10 != 1) // Checks if the digit is neither '0' nor '1'
            {
                printf("Please enter a binary number!\n"); // Prompts to enter a binary number.
                bin = 0;
                break;
            }
            num /= 10;
        }
    }
    while (!bin); // Keeps running as long as the number is "not binary".

    while (binary != 0) // Converts to decimal
    {
        decimal = decimal + (binary % 10) * n;
        binary /= 10;
        n *= 2;
    }

    printf("The decimal equivalent is %d", decimal);

    return 0;
}