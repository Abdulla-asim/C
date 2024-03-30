#include <stdio.h>

#define SIZE 10

int main()
{
    float array[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float *nPtr;

    puts("\nPrinting using array notation:");
    for (int i = 0; i < 10; i++)
        printf("%.1f\t", array[i]);

    // Storing address of the first element of the array in two different ways
    nPtr = &array[0];
    nPtr = array;

    // printing the array using different pointer and array notations
    puts("\nPrinting from nPtr using pointer notation:");
    for (int j = 0; j < 10; j++)
        printf("%.1f\t", *(nPtr + j));

    puts("\nPrinting from array using pointer notation:");
    for (int k = 0; k < 10; k++)
        printf("%.1f\t", *(array + k));

    puts("\nPrinting by subscripting nPtr:");
    for (int l = 0; l < 10; l++)
        printf("%.1f\t", nPtr[l]);

    // Accessing the 4th element using different notations, which should be "3.3"
    printf("\n\n4th element by array subscript notation with array name = %.1f\n", array[3]);
    printf("4th element by pointer/offset notation with array name = %.1f\n", *(array + 3));
    printf("4th element by array subscript notation with nPtr = %.1f\n", nPtr[3]);
    printf("4th element by pointer/offset notation with nPtr = %.1f\n", *(nPtr + 3));

    // Checking the value stored at nPtr + 8, which should be 8.8
    printf("\nAddress referenced by nPtr + 8 = %p\n", nPtr + 8);
    printf("Value stored at nPtr + 8 = %.1f\n", *(nPtr + 8));

    nPtr = &array[5]; // Assuming nPtr stores address of array[5]
    nPtr -= 4; // Now the value at nPtr should be "1.1"
    printf("\nAddress referenced by (nPtr -= 4) = %p\n", nPtr); // Address should be 1002501 according to given.
    printf("Value stored at (nPtr -= 4) = %.1f\n", *nPtr); // Value stored at nPtr after nPtr -= 4, and is "1.1"

    return 0;
}