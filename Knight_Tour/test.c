#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void resetBoard(int board[][8]);

int main() {
    int board[8][8];
    int Horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Vertical[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
    int freq[65] = { 0 };
    int newx, newy;
    int moveCount = 0, triesCount = 0;
    srand(time(NULL));

    do {
        resetBoard(board);
        int x = rand() % 8;
        int y = rand() % 8;
        board[x][y] = 1;
        moveCount = 1;

        for (int count = 2; count <= 64; count++) {
            int moveMade = 0;
            for (int j = 0; j < 8 && !moveMade; j++) {
                newx = x + Horizontal[j];
                newy = y + Vertical[j];

                if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8 && board[newx][newy] == 0)
                {
                    x = newx;
                    y = newy;
                    board[x][y] = count;
                    moveMade = 1;
                }
            }

            if (!moveMade)
            {
                freq[moveCount]++;
                break;
            }
            else
            {
                moveCount++;
            }
        }

        triesCount++;
       

    } while (moveCount != 64);


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }


    for (int i = 1; i < 64; i++)
        printf("\n%d moves were made %d times", i, freq[i]);

    printf("\nIt took %d tries to find a complete tour", triesCount);

    return 0;
}

void resetBoard(int board[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
}