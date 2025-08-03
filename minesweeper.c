// Simple Minesweeper Game in C (console-based)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MINES 3

int board[SIZE][SIZE];
int revealed[SIZE][SIZE];

void placeMines() {
    int placed = 0;
    while (placed < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == 0) {
            board[x][y] = -1;
            placed++;
        }
    }
}

int countMines(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == -1)
                count++;
        }
    }
    return count;
}

void draw() {
    printf("\n   0 1 2 3 4\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                if (board[i][j] == -1) printf("* ");
                else printf("%d ", countMines(i, j));
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int main() {
    char playAgain;
    srand(time(0));
    do {
        // Reset board and revealed
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = 0;
                revealed[i][j] = 0;
            }
        placeMines();
        int x, y, safe = SIZE*SIZE - MINES;
        printf("Welcome to Minesweeper!\nPick a cell (row col) to reveal.\n");
        while (safe > 0) {
            draw();
            printf("Enter row and column: ");
            scanf("%d %d", &x, &y);
            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y]) {
                printf("Invalid cell. Try again.\n");
                continue;
            }
            revealed[x][y] = 1;
            if (board[x][y] == -1) {
                draw();
                printf("Boom! You hit a mine. Game over.\n");
                break;
            }
            safe--;
        }
        if (safe == 0) {
            draw();
            printf("Congratulations! You cleared the board.\n");
        }
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        while (getchar() != '\n' && !feof(stdin));
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
