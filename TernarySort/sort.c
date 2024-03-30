#include <stdio.h>
#include <stdlib.h>

int sort(int a, int b, int c);

void main(int argc, char *argv[])
{
    // getting three numbers as input using command line arguments
    int largest = sort(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])); // converting strings to int

    // printing the largset number
    printf("Largest number is %d\n", largest);
    
}

// Function to sort the three numbers
int sort(int a, int b, int c)
{
    int largest = (a > b)? ((a > c)? a : c) : ((b > c)? b : ((c > a)? c : 0 ));
    return largest;
}