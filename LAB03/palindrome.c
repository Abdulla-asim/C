#include <stdio.h>

void main()
{
    int a, d1, d2, d4, d5;

    printf("Enter a 5-digit number: ");
    scanf("%d", &a);
 // Separates the 1st, 2nd, 4th and 5th digits.
    d5 = (a / 10000);
    d4 = (a % 10000) / 1000;
    d2 = (a % 100) / 10;
    d1 = (a % 10);

// Checks if its a palindrome.
    if (d1 == d5 && d2 == d4)
        printf("%d is a palindrome.\n", a);
    else{
        printf("%d is not a palindrome.\n", a);
    }
}