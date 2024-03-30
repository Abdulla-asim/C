#include <stdio.h>

#define SIZE 10

void print_array(int data[]);

int main()
{
    int data[SIZE];
    puts("DATA ENTRY:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%d", &data[i]);
    }
    for (int j = 0; j < SIZE - 1; j++)
    {
        int smallest = j;
        for (int k = j + 1; k < SIZE; k++)
            if (data[smallest] > data[k]) {
                smallest = k;
                int temp = data[j];
                data[j] = data[smallest];
                data[smallest] = temp;
            }
    }
    print_array(data);
    return 0;
}

void print_array(int data[]) // Print array function
{
    puts("SORTED DATA:");
    for(int i = 0; i < SIZE; i++)
        printf("%d\t", data[i]);
    puts("");
}