// some errors in this code for the brute force problem otherwise it works (fixed)
// the static counter is not being iniitialized to 0 for each loop. (fixed)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimension of board
#define N 8
#define T 1000
/*
global int hor[8], ver[8];
hor[0] =  2; ver[0] = -1;
hor[1] =  1; ver[1] = -2;
hor[2] = -1; ver[2] = -2;
hor[3] = -2; ver[3] = -1;
hor[4] = -2; ver[4] =  1;
hor[5] = -1; ver[5] =  2;
hor[6] =  1; ver[6] =  2;
hor[7] =  2; ver[7] =  1; returns errors*/

// KnightMove{ 0,  1,  2,  3,  4,  5, 6, 7}
int hor[8] = { 2,  1, -1, -2, -2, -1, 1, 2};
int ver[8] = {-1, -2, -2, -1,  1,  2, 2, 1};

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
    int board[N][N], tour_length[T] = {0}, counter;
    srand(time(NULL));

    //print_board(board, "\nFirst Board\n");

    for (int i = 0; i < T; i++)
    {
        init_board(board);
        do
        {
            counter = move_knight(board, tour_length, i);
        } while (counter != -1);
        //print_board(board, "\nFinal Board\n");
    }
    //print_board(board, "\nFinal Board\n");
    print_table(tour_length);
    //puts("No more moves...");
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
int move_knight(int position[][N], int tour_length[], int turn)
{
    static int counter = 1, currentRow = 0, currentCol = 0;
    int  move; // Move number
    if (tour_length[turn] == 0) 
    {
        currentRow = 0;
        currentCol = 0;
        counter = 1;
        position[currentRow][currentCol] = counter;
    }

    move = generate_move(position, currentRow, currentCol);
    if (move == -1) return -1;
    currentRow += ver[move]; // Update row
    currentCol += hor[move]; // Update column
    position[currentRow][currentCol] = ++counter; // Mark the current position
    tour_length[turn]++;

    return counter;
}

// Generate a move to make
int generate_move(int position[][N], int row, int col)
{
    int flag = 0;

    for (int i = 0; i < N; i++) {
        if (safe_move(position, row + ver[i], col + hor[i])) {
            flag = 1;
            break;  // Break out of the loop when a valid move is found
        }
    }

    while (flag) 
    {
        int random = rand() % 8;
        if (safe_move(position, row + ver[random], col + hor[random]))
            return random; // returns move number
    }
    return -1;
}
/*
int generate_move(int position[][N], int row, int col)
{
    int flag = 0;
    for (int i = 0; i < N; i++)
        if (safe_move(position, row + ver[i], col + hor[i])) flag = 1;

    while (flag) 
    {
        int random = rand() % 8;
        if (safe_move(position, row + ver[random], col + hor[random])) return random; // returns move number
    }
    return -1;
}
*/
/*
int generate_move(int position[][N], int row, int col)
{
    for (int i = 0; i < N; i++)
        if (safe_move(position, row + ver[i], col + hor[i])) return i; // returns move number
    return -1;
}
*/

// Check for safe move
int safe_move(int position[][N], int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N && !position[x][y]); // returns true(1) for safe move
}

// Print the board
void print_board(int board[][N], char title[])
{
    printf("%s", title);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%02d ", board[i][j]);
        puts("");
    }
}

void print_table(int data[])
{
    int largest = data[0], loop;
    puts("Turn\tTour Length");
    for (int i = 0; i < T; i++)
    {
        printf("%4d\t%2d\n", i + 1, data[i]);
        if (largest < data[i]) {largest = data[i]; loop = i+1;} 
    }
    printf("\nThe largest tour was of length : %d at %d\n\n", largest, loop);
}