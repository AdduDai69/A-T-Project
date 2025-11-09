#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Rows, columns, diagonals
    for (int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;
    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col, moves, playAgain;
    int scoreX = 0, scoreO = 0;

    do {
        moves = 0;
        currentPlayer = 'X';
        initializeBoard();

        while (1) {
            printBoard();
            printf("Player %c, enter row and column (0-2): ", currentPlayer);
            scanf("%d %d", &row, &col);

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Invalid move. Try again.\n");
                continue;
            }

            board[row][col] = currentPlayer;
            moves++;

            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                if (currentPlayer == 'X') scoreX++;
                else scoreO++;
                break;
            } else if (moves == 9) {
                printBoard();
                printf("It's a draw!\n");
                break;
            }

            switchPlayer();
        }

        printf("Score - Player X: %d | Player O: %d\n", scoreX, scoreO);
        printf("Play again? (1 = Yes, 0 = No): ");
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    printf("Final Score - Player X: %d | Player O: %d\n", scoreX, scoreO);
    printf("Thanks for playing!\n");

    return 0;
}