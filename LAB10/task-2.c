#include <stdio.h>

#define SIZE 10

void print_array(int data[], int size);

int main()
{
    int data[SIZE];
    int i;
    puts("Enter the data (10 integers): "); // Input integers in the array.
    for(i = 0; i < 10; i++){
        printf("Number: ");
        scanf("%d", &data[i]);
    }

    puts("Data in original order: ");
    print_array(data, SIZE);
    puts("\n");
    for(int j = 0; j < SIZE; j++) // Bubble sort.
    {
        for(int i = 0; i < SIZE - j - 1; i++)
        {
            if (data[i] > data[i + 1])
            {
                int temp;
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
        printf("After pass %2d: ", j + 1); 
        print_array(data, SIZE - j); // prints part of the array after every pass.
    }
    print_array(data, SIZE); // prints final sorted array.
    return 0;
}

void print_array(int data[], int size) // Print array function
{
    for(int i = 0; i < size; i++)
        printf("%d\t", data[i]);
    puts("");
}