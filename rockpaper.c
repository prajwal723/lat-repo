// Rock-Paper-Scissors Game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *choices[] = {"Rock", "Paper", "Scissors"};

int main() {
    int user, computer;
    char playAgain;
    srand(time(0));
    printf("Welcome to Rock-Paper-Scissors!\n");
    do {
        printf("Choose your move:\n  1. Rock\n  2. Paper\n  3. Scissors\nYour choice: ");
        scanf("%d", &user);
        while (getchar() != '\n'); // clear input buffer
        if (user < 1 || user > 3) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        computer = rand() % 3 + 1;
        printf("You chose: %s\n", choices[user-1]);
        printf("Computer chose: %s\n", choices[computer-1]);
        if (user == computer) {
            printf("It's a draw!\n");
        } else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        while (getchar() != '\n' && !feof(stdin)); // clear input buffer
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
