#include <stdio.h>

#define SIZE 3

void get_matrix_elements(int matrix[SIZE][SIZE]);
void print_matrix(int matrix[SIZE][SIZE]);
void transpose(int matrix[SIZE][SIZE]);

int main()
{
    int matrix[SIZE][SIZE];
    get_matrix_elements(matrix);
    
    puts("\nOriginal");
    print_matrix(matrix);

    puts("\nTranspose");
    transpose(matrix);
    print_matrix(matrix);

    return 0;
}

void get_matrix_elements(int matrix[SIZE][SIZE])
{
    printf("ENTER MATRIX ELEMENTS:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\nEnter row %d values: \n", i + 1);
        for (int j = 0; j < SIZE; j++)
        {
            printf("Element %d: ", j +1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transpose(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
}

void print_matrix(int matrix[SIZE][SIZE]) // Print matarix
{
    puts("");
    for (int i = 0; i < SIZE; i++)
    {
        printf("[\t");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("]\n");
    }
}

