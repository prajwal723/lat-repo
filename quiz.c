// Simple Quiz Game in C
#include <stdio.h>
#include <string.h>

#define NUM_QUESTIONS 5

struct Question {
    char question[128];
    char options[4][64];
    int correct; // 0-based index
};

int main() {
    struct Question quiz[NUM_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "London", "Paris", "Rome"}, 2},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
        {"Who wrote 'Hamlet'?", {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"}, 1},
        {"What is the largest ocean?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},
        {"Which element has the chemical symbol 'O'?", {"Gold", "Oxygen", "Iron", "Silver"}, 1}
    };
    int score = 0;
    int answer;
    printf("Welcome to the Quiz Game!\n\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Q%d: %s\n", i+1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %d. %s\n", j+1, quiz[i].options[j]);
        }
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer-1 == quiz[i].correct) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is: %s\n\n", quiz[i].options[quiz[i].correct]);
        }
    }
    printf("Quiz Over! Your score: %d/%d\n", score, NUM_QUESTIONS);
    return 0;
}
