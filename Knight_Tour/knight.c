// Brute force knight's tour Problem.
// ABDULLAH
// 455340
// BSCS-13-B

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimension of board
#define N 8
#define T 1000

// KnightMove{ 0,  1,  2,  3,  4,  5, 6, 7}
int hor[8] = { 2,  1, -1, -2, -2, -1, 1, 2};
int ver[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int counter, currentRow, currentCol;

// Fucntion prototypes
int generate_move(int position[][N], int row, int col);
void init_board(int board[][N]);
int move_knight(int position[][N],int length[], int turn);
void print_board(int board[][N], char title[]);
void print_table(int data[]);
int safe_move(int position[][N], int x, int y);

// Main Function
int main()
{
    int board[N][N], result;
    int tour_length[T] = {0};
    srand(time(NULL));

    //for (int i = 0; i < T; i++) // UNCOMMENT for Thousand loops brute force (ALSO UNCOMMENT LINE 73 and 54)
    for (int i = 0; counter != 64; i++) // Infinite loop brute force until 64 tour length. (ALSO UNCOMMENT LINE 49, 50) and comment out the upper line.
    {
        init_board(board);
        counter = 1;
        currentRow = rand() % 8; // Starting row 0
        currentCol = rand() % 8; // Starting column 0
        board[currentRow][currentCol] = counter; // Mark the current position

        do
            result = move_knight(board, tour_length, i);
        while (result != -1);
        //print_board(board, "\nINSIDE LOOP\n");
        if (counter > 62) 
        {
            print_board(board, "\nGreater than 60 Board.\n");
            printf("\nThe length of the tour was %d\nand the number of loop was %ld\n", counter, i+1);
        }

    }
    
    print_board(board, "\nFinal Board\n"); // COMMETN/UNCOMMENT
    //print_table(tour_length); // COMMENT/UNCOMEMNT this.

    return 0;
}

// Initialize all the board squares to 0
void init_board(int board[][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
}

// Move the knight
int move_knight(int position[N][N], int tour_length[], int turn)
{
    int  move; // Move number
    move = generate_move(position, currentRow, currentCol); // Store the generated move's index in move
    if (move == -1) return -1;
    currentRow += ver[move]; // Update row
    currentCol += hor[move]; // Update column
    position[currentRow][currentCol] = ++counter; // Mark the current positionc
    //tour_length[turn]++; // Uncomment for thousand loops

    return 0;
}

// Generate a move to make
int generate_move(int position[][N], int row, int col)
{
    int flag = 0;
    for (int i = 0; i < N; i++)
        if (safe_move(position, row + ver[i], col + hor[i])) // Checks if there is a possible move
        {
            flag = 1;
            break;
        }

    while (flag) 
    {
        int random = rand() % 8;
        if (safe_move(position, row + ver[random], col + hor[random])) return random; // returns move number
    }
    return -1;
}

// Check for safe move
int safe_move(int position[][N], int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N && !position[x][y]); // returns true (1) for safe move
}

// Print the board function
void print_board(int board[][N], char title[])
{
    printf("%s", title); // Prints the title of the board
    // Print board
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%02d ", board[i][j]);
        puts("");
    }
}

// Print table function
void print_table(int data[])
{
    int largest = data[0];
    puts("Turn\tTour Length"); // Headings
    for (int i = 0; i < T; i++)
    {
        printf("%4d\t%2d\n", i + 1, data[i]);
        if (largest < data[i]) largest = data[i];
    }
    printf("\nThe largest tour was of length : %d\n\n", largest); // Prints the largest tour and the loop number
}