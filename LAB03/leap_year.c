// Checks if the year is a leap year or not.
#include <stdio.h> // Abdullah, 455340

void main()
{
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0 && year % 100 != 0)
        printf("%d is a leap year.\n", year);
    else if (year % 400 == 0)
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);
}