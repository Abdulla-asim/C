#include <stdio.h>

#define SIZE 10

void print_array(int data[], int size);

int main()
{
    int data[SIZE];
    int i;
    puts("Enter the data (10 integers): ");
    for(i = 0; i < 10; i++){
        printf("Number: ");
        scanf("%d", &data[i]);
    }

    for(int j = 0; j < SIZE; j++)
        for(int i = 0; i < SIZE - j - 1; i++)
        {
            if (data[i] < data[i + 1])
            {
                int temp;
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    print_array(data, SIZE);
    return 0;
}

void print_array(int data[], int size)
{
    printf("Sorted Data: \n");
    for(int i = 0; i < size; i++)
        printf("%d\t", data[i]);
}