#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum options_type {
  STUDY = 1, CREATE, QUIT
};

typedef struct Flashcard {
  char question[100];
  char answer[200];
} flashcard;

typedef struct Flashcards {
  int amount_of_cards;
  flashcard all_flashcards[10];
} flashcards;

void add_flashcard(flashcards *flashcards, char *question, char *answer) {
  static int current_flashcard = 0;
  flashcard new_flashcard;
  
  //TODO: scanf cannot read entire lines
  strcpy(new_flashcard.question, question);
  strcpy(new_flashcard.answer, answer);

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

//TODO this might be better being a loop over an array of options
//Not use enums but using an array
void print_main_menu(void) {
  puts(---- Main Menu ----\n);
  for(int i = 0; i < 3; i++) {
    puts("[%d]") // need to be able to create an array with strings
  }
  puts("---- Main Menu ----\n[1] Create flashcard\n[2] Quit");
}

void study_flashcards(flashcards *flashcards) {
  for(int i = 0; i < flashcards->amount_of_cards; i++) {
    printf("%s", flashcards->all_flashcards[i].question);
    scanf("");
    printf("%s", flashcards->all_flashcards[i].answer);
  }
}

int main() {
  flashcards all_cards = {0};

  while(true) {
    int option;
    print_main_menu();
    scanf("%d", &option);

    switch(option) {
      case STUDY:
            study_flashcards(&all_cards);
            break;
      case CREATE:
        add_flashcard(&all_cards, "What is the capitol of france?", "Paris"); 
        add_flashcard(&all_cards, "What is the mother of all programming languages?", "C"); 
        print_flashcards(&all_cards);
        break;
      case QUIT:
        break;
    }

    if (option == QUIT) break;
  }

  return EXIT_SUCCESS;
}
