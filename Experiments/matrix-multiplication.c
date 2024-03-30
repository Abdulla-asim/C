#include <stdio.h>

//prototypes
void getMatrixElements(int row, int col, int array[row][col]);
void multiplyMatrices(int size_1[], int size_2[],int rows,int cols, int result[rows][cols]);
void display(int row,int col,int matrix[row][col]);

//declare variables
int matrix_A[100][100] = {0};
int matrix_B[100][100] = {0};



int size_A[2] = {-1,-1}; //holds size given by user for matrix a
int size_B[2] = {-1,-1}; //holds size given by user for matrix b


int main(void)
{

    //get inputs from user

    do
    {

    printf("Remember to enter valid sizes!\n\n");

    printf("Please enter row size of Matrix A: ");
    scanf(" %d", &size_A[0]);

    printf("Please enter column size of Matrix A: ");
    scanf(" %d", &size_A[1]);

    printf("Please enter row size of Matrix B: ");
    scanf(" %d", &size_B[0]);

    printf("Please enter column size of Matrix B: "); // Fixed typo here
    scanf(" %d", &size_B[1]);
}
while (size_A[1] != size_B[0]);


int matrix_C[100][100] = {0};

    //populate the array now
    printf("\nNow enter the values of the matrix A\n\n");
    getMatrixElements(size_A[0], size_A[1], matrix_A);

    //display(size_A[0],size_A[1],matrix_A);

    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("\n\n %d  ", matrix_A[i][j]);
        }
    }
    printf("\nNow enter the values of the matrix B\n\n");
    getMatrixElements(size_B[0], size_B[1], matrix_B);

    display(size_B[0],size_B[1],matrix_B);


    printf("abc:  %d\n", matrix_B[1][0]);


    //now multiply the matrices
    multiplyMatrices(size_A, size_B, size_A[0],size_B[1], matrix_C);

    printf("\n\n");
    //display resultant
    display(size_A[0],size_B[1],matrix_C);

    return 0;
}

//TODO

void getMatrixElements(int row, int col, int array[row][col]) {
    for (int i = 0; i < row; i++) {

        printf("Enter row %d values\n", i + 1);

        for (int j = 0; j < col; j++) {

            printf("Enter value: ");
            scanf(" %d", &array[i][j]);
        }
    }
    return;
}


//TODO

void multiplyMatrices(int size_1[], int size_2[],int rows,int cols, int result[rows][cols])
{
    int row1= size_1[0];
    int col1 = size_1[1];

    int row2= size_2[0];
    int col2 = size_2[1];

    printf("%d\n", matrix_A[1][0]);
    printf("%d", matrix_B[1][0]);
    for (int i = 0; i < row1; i++) //loop over the rows of the first matrix
    {
        for (int j = 0; j < col2; j++)//cols of two
        {
            result[i][j] = 0;

            for (int a = 0; a < col1; a++) //cols of 1
            {
                result[i][j] += matrix_A[i][a] * matrix_B[a][j];
            }

        }
    }

    return;
}

void display(int row, int col,int matrix[row][col])
{
    for (int i = 0; i < row; i++)
    {
        printf("[  ");
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("  ]\n");
    }
    return;
}