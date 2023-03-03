#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function that records the data in file
void recorder(char name[], char answer[], char status[]) {
  FILE *fp;
  fp = fopen("helo.txt", "a");
  fprintf(fp, "\n%s\t%s\t%s", name, answer, status);
  fclose(fp);
}

// function that prints the saved data in the file
void records() {
  char name[50], answer[50], status[50];
  FILE *fp;
  int i = 1;
  system("clear");
  printf(" __________________________________________________________\n");
  printf("|                    Match History                         |\n");
  printf(" __________________________________________________________\n\n\n");
  fp = fopen("helo.txt", "r");
  while((fscanf(fp,"%s%s%s\n",name,answer,status))!=EOF) {
  printf("%d.\tPlayer: %s\tKeyword: %s\tStatus: %s\n\n", i, name,answer, status);
    i++;
  }
  exit(0);
  fclose(fp);
}

// main function
int main() {
system("clear");
  int flag = 0, count = 0;
  char answer[128], name[50];
  char option;

  printf("****************** Welcome To Hangman ******************\n\n");
  printf("Let's go through the rules first!!\n");
  printf("# You will be starting the game with 5 lives.\n");
  printf("# For every incorrect guess your life will turn to ash.\n");
  printf("# If you lose all of your lives you are going to get hanged!!\n\n");
  printf("Now let's begin!!!\n\n");
  printf("----------------------------------------------------------\n\n");

  // asks the user to see the record or start the game based on the answer they
  // give
  printf("Note: Type \"r\" to view match history and \"s\" to start a match.\n\n");
  scanf(" %c", &option);
  while (1) {
    if (option == 'r') {
      records();
    } else if (option == 's') {
      break;
    } else {
      int a;
      printf("\nThe code is invalid. Enter a correct option: ");
      scanf(" %c", &option);
    }
  }

  // runs after the game starts
  system("clear");
  printf("****************** Welcome To Hangman ******************\n\n");
  printf("Let's go through the rules first!!\n");
  printf("# You will be starting the game with 5 lives.\n");
  printf("# For every incorrect guess your life will turn to ash.\n");
  printf("# If you lose all of your lives you are going to get hanged!!\n\n");
  printf("Now let's begin!!!\n\n");
  printf("----------------------------------------------------------\n\n");
  printf("\n\nEnter keyword for others to guess: ");
  scanf(" %s", answer);

  // array named mask is created which is same length as our keyword
  // mask consists all the elements 0
  system("clear");
  int N = strlen(answer);
  int mask[N];
  for (int i = 0; i < N; ++i) {
    mask[i] = 0;
    answer[i] = tolower(answer[i]);
  }

  printf("You have 5 lives.\n\n");
  printf("__________________________________________________________\n");
  printf("__________________________________________________________\n\n");

  int gameover = 1;
   printf("Enter the gusser's username: ");
  scanf("%s", &name);
  // creats infinite loop until its 0
  while (gameover) {
    flag = 0;
     

    printf("\nThe word is : ");

    // reveals the character of answer if corresponding element in mask is 1.
    // But if the mask is 0 then it prints *
    for (int j = 0; j < N; ++j) {
      if (mask[j]) {
        printf("%c", answer[j]);
      } else {
        printf("*");
      }
    }
    printf("\n");

    // takes the guess of user
    char guess;
    printf("\nGuess a Letter: ");
    scanf(" %c", &guess);
    guess = tolower(guess);

    // compares the guessed letter with each element of the answer array. And if
    // the guess matches the answer, the corresponding element in mask is
    // assigned 1.
    //  flag is also assigned 1 to notify that the guessed letter is correct.

    for (int j = 0; j < N; ++j) {
      if (answer[j] == guess) {
        mask[j] = 1;
        flag = 1;
      }
    }

    // if flag is equals to zero it indicates that the guess was wrond so it
    // prints the guess was wrong
    if (flag == 0) {
      count++;
      system("clear");
      printf("\nYou have %d lives remaining!!\n", 5 - count);
      printf("____________________________________________\n");
      printf("____________________________________________\n");
    }

    // if flag is not 0 it indicates that the guess was right so it prints the
    // guess was right.
    else {
      system("clear");

      printf("\nNice that was correct!!!!\n");
      printf("Still %d lives remaining.\n", 5 - count);
      printf("____________________________________________\n");
      printf("____________________________________________\n\n");
    }

    // this checks if all the letters have been guessed and if all the letters
    // are guessed it breaks the loop.
    gameover = 0;
    for (int j = 0; j < N; ++j) {
      if (!mask[j]) {
        gameover = 1;
        break;
      }
    }

    // if life is 0 than again it breaks the loop
    if (count == 5) {
      break;
    }
  }

  // if flag is 1 while the loop broke than the player has won
  if (flag == 1) {
    char status[] = "won";
    system("clear");
    printf("The word was indeed \"%s\".\n", answer);
    printf("You escaped death. Congratulations I guess.");
    recorder(name, answer, status);
  }

  // if flag is 0 while the loop broke the player lost
  else {
    char status[] = "lost";
    printf("You died!!! \t Thank You for your soul!!!\n\n");
    printf("The key word was \"%s\"", answer);
    recorder(name, answer, status);
  }

  return 0;
}