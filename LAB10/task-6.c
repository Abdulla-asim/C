#include <stdio.h>

#define SIZE 3

void get_matrix_elements(int matrix[SIZE][SIZE]);
void print_matrix(int matrix[SIZE][SIZE], char title[]);
void print_float_matrix(float matrix[SIZE][SIZE], char title[]);
void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int r, int c, int size);
void adjoint(int matrix[SIZE][SIZE], int adj[SIZE][SIZE]);
int determinant(int matrix[SIZE][SIZE], int size);
int inverse(int matrix[SIZE][SIZE], float inverse[SIZE][SIZE]);

int main()
{
    int matrix[SIZE][SIZE];
    int matrix_adj[SIZE][SIZE];
    float matrix_inv[SIZE][SIZE];

    get_matrix_elements(matrix);

    print_matrix(matrix, "\nOriginal Matrix:\n");

    if ((inverse(matrix, matrix_inv))) print_float_matrix(matrix_inv, "The inverse of A is:\n");

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

void print_float_matrix(float matrix[SIZE][SIZE], char title[]) // Print matrix
{
    printf("%s", title);
    for (int i = 0; i < SIZE; i++)
    {
        printf("[\t");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("]\n");
    }
}

void adjoint(int matrix[SIZE][SIZE], int adj[SIZE][SIZE])
{
    int sign = 1, temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            get_cofactor(matrix, temp, i, j, SIZE);

            sign = ((i + j) % 2 == 0) ? 1 : -1;

            adj[i][j] = sign * determinant(temp, SIZE - 1);
        }
    }
}

int determinant(int matrix[SIZE][SIZE], int size)
{
    int deter = 0;
    if (size == 1)
        return matrix[0][0];

    int temp[SIZE][SIZE];
    int sign = 1;

    for (int i = 0; i < size; i++)
    {
        get_cofactor(matrix, temp, 0, i, size);
        deter += sign * matrix[0][i] * determinant(temp, size - 1);
        sign = -sign;
    }

    return deter;
}


void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int r, int c, int size)
{
    int row = 0, col = 0;
 
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)
            if (i != r && j != c)
            {
                temp[row][col++] = matrix[i][j];
                if (col == size - 1)
                {
                    col = 0;
                    row++;
                }
            }
}

int inverse(int matrix[SIZE][SIZE], float inverse[SIZE][SIZE])
{
    int deter = determinant(matrix, SIZE);
    if (deter == 0)
    {
        printf("Singular matrix, can't find its inverse");
        return 0;
    }

    int adj[SIZE][SIZE];
    adjoint(matrix, adj);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            inverse[i][j] = adj[i][j] / (float)deter;

    return 1;
}
