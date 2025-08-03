// Dice Rolling Game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll, sides = 6;
    char playAgain;
    srand(time(0));
    printf("Welcome to the Dice Rolling Game!\n");
    do {
        roll = rand() % sides + 1;
        printf("You rolled a %d!\n", roll);
        printf("Roll again? (y/n): ");
        playAgain = getchar();
        while (getchar() != '\n');
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
