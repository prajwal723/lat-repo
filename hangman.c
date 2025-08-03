// Simple Hangman Game in C
#include <stdio.h>
#include <string.h>

int main() {
    char playAgain;
    const char *words[] = {"computer", "hangman", "program", "science", "window", "keyboard", "mouse", "screen"};
    int numWords = sizeof(words)/sizeof(words[0]);
    srand(time(0));
    do {
        int idx = rand() % numWords;
        const char *word = words[idx];
        char guessed[20];
        int len = strlen(word);
        for (int i = 0; i < len; i++) guessed[i] = '_';
        guessed[len] = '\0';
        int attempts = 7, win = 0;
        char guess;
        printf("Welcome to Hangman!\n");
        while (attempts > 0 && !win) {
            printf("Word: %s\n", guessed);
            printf("Attempts left: %d\n", attempts);
            printf("Guess a letter: ");
            scanf(" %c", &guess);
            int found = 0;
            for (int i = 0; word[i] != '\0'; i++) {
                if (word[i] == guess && guessed[i] == '_') {
                    guessed[i] = guess;
                    found = 1;
                }
            }
            if (!found) attempts--;
            win = strcmp(word, guessed) == 0;
        }
        if (win) printf("You win! The word was: %s\n", word);
        else printf("You lose! The word was: %s\n", word);
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        while (getchar() != '\n' && !feof(stdin)); // clear input buffer
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
