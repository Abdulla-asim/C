#include <stdio.h>

#define SIZE 3

//int[][] adjoint(int matrix[SIZE][SIZE]);
int det(int matrix[SIZE][SIZE]);
void get_matrix_elements(int matrix[SIZE][SIZE]);
//void inverse(int matrix[SIZE][SIZE], int inverse[SIZE][SIZE]);
void print_matrix(int matrix[SIZE][SIZE], char title[]);


int main()
{
    int matrix[SIZE][SIZE];
    int inverse[SIZE][SIZE];
    get_matrix_elements(matrix);

    print_matrix(matrix, "\nOriginal Matrix:\n");

    int determinant = det(matrix);
    printf("\nDteterminant = %d", determinant);

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

/* V WRONG ANSWER
int det(int m[SIZE][SIZE])
{
    int determinant = 0;
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 1; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (j != k)
                {
                    if (i == 1) determinant = (m[i][j] * m[i + 1][j + 2]) - (m[i][j + 2] * m[i + 1][j]);
                    else determinant = (m[i][j] * m[i + 1][j + 1]) - (m[i][j + 1] * m[i + 1][j]);
                }
        if (k == 1) determinant = -m[0][k] * determinant;
        else determinant = m[0][k] * determinant;
    }
    return determinant;
}
*/

/*
int det(int m[SIZE][SIZE])
{
    int row, col, determinant = 0;
    for (int k = 0; k < SIZE; k++)
    {
            row = 1;
            col = 0;
            if (col != k)
            {
                if (k == 1) determinant = (m[row][col] * m[row + 1][col + 2]) - (m[row][col + 2] * m[row + 1][col]);
                else determinant = (m[row][col] * m[row + 1][col + 1]) - (m[row][col + 1] * m[row + 1][col]);
            }
        row++;
        col++;
        if (k == 1) determinant = -1*m[0][k] * determinant;
        else determinant = m[0][k] * determinant;
    }
    return determinant;
}
*/

/*
int det(int m[SIZE][SIZE])
{
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
           m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
           m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
*/



