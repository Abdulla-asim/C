#include <stdio.h> // Abdullah, 455340

void main()
{
    int a, largest , smallest;

    printf("Enter a number: ");
    scanf("%d", &a);

    largest = a; // Default values
    smallest = a;

    for(int i = 0; i < 4; i++)
    {
        printf("Enter another number: ");
        scanf("%d", &a);

        if(a > largest) // Stores the greater number in largest
            largest = a;
        else            // Stores the smaller number in smallest
            smallest = a;
    }

    printf("Largest = %d\n", largest);
    printf("Smallest = %d\n", smallest);
}