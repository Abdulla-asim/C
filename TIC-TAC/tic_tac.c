#include <stdio.h>

void print_board(char board[][3]);
int player(char board[][3], int player, char symbol);
int update_board(char board[][3], int x, int y, int sign);
int win(char b[][3], int player, int x, int y, char sym);

int main()
{
    char sym1, sym2, game, board[3][3];
    
    // Initializing the board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';

    // Enter the symbol to be used 
    printf("Player-1 symbol: ");
    scanf(" %c", &sym1);
    printf("Player-2 symbol: ");
    scanf(" %c", &sym2);

    // Loop until someone wins
    do {
        while (1)
        {
            print_board(board);
            if (player(board, 1, sym1)) break;
            print_board(board);
            if (player(board, 2, sym2)) break;
        }
        printf("Do you want to play again (y/n) ? ");
        scanf("%s", &game);
    } while(game == 'Y' || game == 'y');

    return 0;
}

// Print board
void print_board(char board[][3])
{
    puts("");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            printf("%c\t", board[i][j]);
        puts("");
    }
}

int player(char board[][3], int player, char symbol)
{
    int updated, x, y, count;
    do{
        printf("\nPLAYER-%d:\n", player);
        printf("Row Column (x y): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        
    } while (!(update_board(board, x, y, symbol)) || x < 0 || x > 2 || y < 0 || y > 2);

    if (win(board, player, x, y, symbol))
        {
            print_board(board);
            printf("\nPLAYER-%d wins!!", player);
            return 1;
        }

    return 0;
}

int update_board(char board[][3], int x, int y, int sign)
{
    if (board[x][y] == '-') board[x][y] = sign;
    else 
    {
        puts("\nPlease enter an unfilled co-ordinate...\n");
        return 0;
    }
    return 1;
}

int win(char b[][3], int player, int x, int y, char sym)
{
    // counter matrix {horizontal, vertical, main-diagonal, anti-diagonal}
    int count[4] = {0};
    int p = 0, q = 2;

    for (int i = 0; i < 3; i++)
    {
        if (b[x][(y + i) % 3] == sym) count[0]++;
        if (b[(x + 1) % 3][y] == sym) count[1]++;
        if ((x == y) && b[(x + i) % 3][(x + i) % 3] == sym) count[2]++;
        if ((x + y == 2) && (b[p++][q--] == sym)) count[3]++;
    }
    for (int j = 0; j < 3; j++)
        if (count[j] == 3) return 1;
    return 0;
}
