// Simple Memory Match Game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cards[4] = {1, 2, 1, 2};
    int revealed[4] = {0, 0, 0, 0};
    int first, second, matches = 0;
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    printf("Welcome to Memory Match!\nPick two cards (0-3) to find a pair.\n");
    while (matches < 2) {
        printf("Cards: ");
        for (int i = 0; i < 4; i++) printf("%s ", revealed[i] ? "*" : "?");
        printf("\nPick first card: ");
        scanf("%d", &first);
        printf("Pick second card: ");
        scanf("%d", &second);
        if (first == second || first < 0 || first > 3 || second < 0 || second > 3 || revealed[first] || revealed[second]) {
            printf("Invalid pick. Try again.\n");
            continue;
        }
        if (cards[first] == cards[second]) {
            printf("Match!\n");
            revealed[first] = revealed[second] = 1;
            matches++;
        } else {
            printf("No match.\n");
        }
    }
    printf("You found all pairs!\n");
    return 0;
}
