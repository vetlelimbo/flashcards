#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum options {
  CREATE = 1, QUIT
};

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

void print_main_menu(void) {
  puts("---- Main Menu ----\n[1] Create flashcard\n[2] Quit");
}

int main() {
  flashcards all_cards = {0};

  while(true) {
    int option;
    print_main_menu();
    scanf("%d", &option);

    switch(option) {
      case CREATE:
        add_flashcard(&all_cards); 
        print_flashcards(&all_cards);
        break;
      case QUIT:
        break;
    }

    if (option == QUIT) break;
  }

  return EXIT_SUCCESS;
}
