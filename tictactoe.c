#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
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
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void getMove(char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column: 1-3 1-3): ");
        if (scanf("%d %d", &row, &col) != 2) {
            while (getchar() != '\n'); // clear input
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid position. Try again.\n");
            continue;
        }
        if (board[row-1][col-1] != ' ') {
            printf("Cell already taken. Try again.\n");
            continue;
        }
        board[row-1][col-1] = player;
        break;
    }
}

int main() {
    char currentPlayer = 'X';
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    printBoard();
    while (1) {
        getMove(currentPlayer);
        printBoard();
        if (checkWin()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
