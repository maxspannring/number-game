//this is just a simple game i made to practice my C skills

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>

int main() {
  /* declaring variables*/
  int r;
  time_t t;
  bool guessed = false;
  int remaining_tries = 6;
  int guessed_number;

  srand((unsigned) time(&t)); // initializes random number generator
  r = rand() % 100;   // random number between 0 & 100
  printf("\033[1;34m==========================\n");
  printf("Guess the Number!🎲\n");
  printf("Max Spannring, Jun 25 2020\n");
  printf("==========================\n");

  while (guessed == false && remaining_tries > 0) {
    printf("\033[0mRemaining tries: %d\n", remaining_tries);

    if (scanf("%d", &guessed_number) != 1){
      printf("\033[0;31mThis is not a valid input!❎\n");
      return(0);
    }

    if (guessed_number < r) {
      printf("\033[0;33mToo low!🔼\n");
    } else if (guessed_number > r) {
      printf("\033[0;33mToo high!🔽\n");
    } else {
      printf("\033[1;32m=========================================\n");
      printf("Congratulations! Your guess is correct🏆\n");
      printf("=========================================\n");
      guessed = true;
      return(0);
    }

    remaining_tries = remaining_tries-1;  // decreases the remaining tries
    if (remaining_tries == 0) {
      printf("\033[0;31mSorry, You're out of tries!\n");
      printf("The number would have been: %d\n", r);
      return(0);
    }
  }
  return(0);
}
