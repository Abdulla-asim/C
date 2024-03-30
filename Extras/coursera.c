#include <stdio.h>

float average(int array[], int size);

int sum = 0;


void main()
{
    FILE *weights; // Makes a file pointer

    weights = fopen ("weights.txt", "r"); // Stores the file data (weights) in the file pointer

    int size = 1000;
    int array[size]; // Creates an aray of integers
    for (int i = 0; i < 1000; i++) // Stores the weights in the array
        fscanf(weights, "%d", &array[i]);

    float avg = average(array, size);

    printf("Average weight of elephant seals: %.3f\n", avg); // Prints the average weight

    fclose(weights);

}

float average(int array[], int size) // Function to calculate the average of the data inside the array
{

    for (int i = 0; i < size; i++) // Finds the sum of all the weights
        sum = sum + array[i];

    return sum / (float) size; // Returns the average weight
}