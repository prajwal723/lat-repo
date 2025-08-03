// Simple Pong Game in C (console-based)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int ballX, ballY, ballDX = 1, ballDY = 1;
int paddleY = HEIGHT / 2;
int score = 0;

void draw() {
    system("cls");
    for (int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) {
                if (i >= paddleY-2 && i <= paddleY+2) printf("|");
                else printf("#");
            } else if (i == ballY && j == ballX) {
                printf("O");
            } else {
                printf(" ");
            }
            if (j == WIDTH-1) printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'w' && paddleY > 2) paddleY--;
        if (ch == 's' && paddleY < HEIGHT-3) paddleY++;
    }
}

void logic() {
    ballX += ballDX;
    ballY += ballDY;
    if (ballY <= 0 || ballY >= HEIGHT-1) ballDY = -ballDY;
    if (ballX == 1) {
        if (ballY >= paddleY-2 && ballY <= paddleY+2) {
            ballDX = -ballDX;
            score++;
        } else {
            ballX = WIDTH/2; ballY = HEIGHT/2; score = 0;
        }
    }
    if (ballX >= WIDTH-1) ballDX = -ballDX;
}

int main() {
    ballX = WIDTH/2; ballY = HEIGHT/2;
    printf("Welcome to Pong! Use W/S to move paddle.\n");
    while (1) {
        draw();
        input();
        logic();
        Sleep(50);
    }
    return 0;
}
