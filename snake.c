// Simple Snake game in C (console-based)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int gameOver;
char dir;

void setup() {
    gameOver = 0;
    dir = 's';
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }
            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = 'l'; break;
            case 'd': dir = 'r'; break;
            case 'w': dir = 'u'; break;
            case 's': dir = 'd'; break;
            case 'x': gameOver = 1; break;
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
        case 'l': x--; break;
        case 'r': x++; break;
        case 'u': y--; break;
        case 'd': y++; break;
    }
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) gameOver = 1;
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) gameOver = 1;
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

int main() {
    char playAgain;
    do {
        setup();
        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(200);
        }
        printf("Game Over! Final Score: %d\n", score);
        printf("Do you want to play again? (y/n): ");
        fflush(stdin);
        playAgain = getchar();
        while (getchar() != '\n'); // clear input buffer
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
