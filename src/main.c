#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

char *duplicate;		/* Seperate string for duplication */

int main(){
  int i;
  char* string = "Hello world! Look!!! My beautiful wife is checking out my work! Isn't she amazing?!";

  printf("Test string is: %s\n\n", string);
  //for (i = 0; string[i] != '\0'; i++){
    //printf("Is there a char at position is %d? %s\n", i,
    //	   (non_space_char(string[i]) == 1) ? "Yes" : "No");
    // printf("Is there a white space at position is %d? %s\n", i,
    //(space_char(string[i]) == 1) ? "Yes" : "No");
  //}

  //printf("There's a word that starts with '%c' ", word_start(string));
  //printf("and that word ends with '%c'\n", word_end(string));
  //printf("This string contains %d words\n", count_words(string));
  //duplicate = copy_str(string, 38);
  //printf("Copied string %s.\nHere's the new copied string: %s\n", string, duplicate); 
  //printf("Let's free that copied string.\n");
  //freeStr(duplicate);
  //printf("Trying to print copied string: %s\n", duplicate);

  //printf("The first char of the first word in string is %c.\n", word_start(string));
  //printf("The last char of the first word in string is %c.\n", word_end(string));
  //printf("The # of chars is %d.\n", countChars);
  //tokenize(string);
  //print_tokens(tokens);
  //free_tokens(tokens);

  history = init_history();
  add_history(history, string);
  printf("History str: %s\n", history->root->str);
  printf("History ID: %d\n", history->root->id);
  printf("History next: %s\n", (history->root->next == NULL) ? YES: NO);
  add_history(history, "I guess that's over.\n");
  add_history(history, "Just kidding! Here's more strings fo' yo' history!\n");
  printf("\nString in history is %s\n", get_history(history, 1));
  
  return 0;
}
