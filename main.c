#include <stdio.h>
#include <stdlib.h>

typedef struct Flashcard {
  char question[100];
  char answer[200];
} flashcard;

void add_flashcard() {
  static int current_flashcard = 0;
  flashcard new_flashcard;
  printf("Question: ");
  
  //TODO: scanf cannot read entire lines
  scanf("%s", new_flashcard.question);
  printf("Answer: ");
  scanf("%s", new_flashcard.answer);
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

  add_flashcard();
  
  return EXIT_SUCCESS;
}
