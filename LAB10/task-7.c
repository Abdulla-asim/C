#include <stdio.h>

#define SIZE 3

void print_matrix(int matrix[SIZE][SIZE], char title[]);
void get_matrix_elements(int matrix[SIZE][SIZE]);
void multiply_matrix(int matrix1[][SIZE], int matrix2[][SIZE],int matrix_m[][SIZE]);


int main()
{
    int matrix1[SIZE][SIZE]; // Matrix A.
    int matrix2[SIZE][SIZE]; // Matrix B.
    int matrix_m[SIZE][SIZE]; // matrix after multiplication.

    puts("\nMatrix A");
    get_matrix_elements(matrix1);
    puts("\nMatrix B");
    get_matrix_elements(matrix2);

    print_matrix(matrix1, "\nA:\n");
    print_matrix(matrix2, "\nB:\n");

    multiply_matrix(matrix1, matrix2, matrix_m);
    print_matrix(matrix_m, "\nA x B\n");

    return 0;
}

void get_matrix_elements(int matrix[SIZE][SIZE])
{
    printf("ENTER MATRIX ELEMENTS\n");
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

void print_matrix(int matrix[SIZE][SIZE], char title[]) // Print matarix
{
    printf("%s", title);
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


void multiply_matrix(int matrix1[][SIZE], int matrix2[][SIZE], int matrix_m[][SIZE])
{
    for (int k = 0; k < SIZE; k++)
        for (int i = 0; i < SIZE; i++)
        {
            int sum = 0;
            for (int j = 0; j < SIZE; j++)
                sum += matrix1[i][j] * matrix2[j][i];
            matrix_m[k][i] = sum;
        }
}

