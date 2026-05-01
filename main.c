#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flashcard {
  char question[100];
  char answer[200];
} flashcard;

typedef struct Flashcards {
  int amount_of_cards;
  flashcard all_flashcards[10];
} flashcards;

void add_flashcard(flashcards *flashcards) {
  static int current_flashcard = 0;
  flashcard new_flashcard;
  
  //TODO: scanf cannot read entire lines
  strcpy(new_flashcard.question, "What is the capitol of france?");
  strcpy(new_flashcard.answer, "Paris");

  flashcards->all_flashcards[flashcards->amount_of_cards] = new_flashcard;
  flashcards->amount_of_cards++;
}

void print_flashcards(const flashcards *flashcards) {
  const int amount = flashcards->amount_of_cards;
  for (int i = 0; i < amount; i++) {
    printf("Question: %s\nAnswer: %s\n", 
        flashcards->all_flashcards[i].question,
        flashcards->all_flashcards[i].answer);
  }
}

int main() {
  // The falshcards data structure
  flashcards all_cards = {0};
  add_flashcard(&all_cards);
  print_flashcards(&all_cards);

  return EXIT_SUCCESS;
}
