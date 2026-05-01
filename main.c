#include <stdio.h>
#include <stdlib.h>

typedef struct Flashcard {
  char question[100];
  char answer[200];
} flashcard;

void add_flashcard(flashcard flashcards[], flashcard *card) {
  static int current_flashcard = 0;
  flashcards[current_flashcard] = *card;
}

void print_flashcards(const flashcard* flashcards) {
  for (int i = 0; i < 10; i++) {
    printf("Question: %s\nAnswer: %s\n", 
        flashcards[i].question,
        flashcards[i].answer);
  }
}

int main() {
  flashcard flashcards[10];

  flashcard flashcard1 = {
    .question = "What is the capitol of france?",
    .answer = "Paris"
  };

  add_flashcard(flashcards, &flashcard1);
  print_flashcards(flashcards);
  
  return EXIT_SUCCESS;
}
