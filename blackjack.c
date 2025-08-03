// Simple Blackjack Game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int drawCard() {
    int card = rand() % 13 + 1;
    if (card > 10) return 10;
    return card;
}

int main() {
    int player = 0, dealer = 0;
    char choice;
    srand(time(0));
    printf("Welcome to Blackjack!\n");
    player = drawCard() + drawCard();
    dealer = drawCard() + drawCard();
    printf("Your total: %d\n", player);
    do {
        printf("Hit or stand? (h/s): ");
        choice = getchar();
        while (getchar() != '\n');
        if (choice == 'h') {
            int card = drawCard();
            player += card;
            printf("You drew a %d. Total: %d\n", card, player);
        }
    } while (choice == 'h' && player < 21);
    printf("Dealer's total: %d\n", dealer);
    if (player > 21) printf("Bust! You lose.\n");
    else if (player > dealer || dealer > 21) printf("You win!\n");
    else if (player == dealer) printf("Draw!\n");
    else printf("Dealer wins!\n");
    return 0;
}
