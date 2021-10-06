#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"
#include "history.c"

#define MAXLINE 1000 /* Max input length */

List *history;
char *duplicate;		/* Seperate string for duplication */

int main(){
  int i, c, len;
  char string[MAXLINE];
  int repeat = 1;
  
  printf("Enter string for processing: \n");
  i = 0;
  while (i < MAXLINE-2 && (c = getchar()) != EOF && c != '\n')
    string[i++] = c;
  if(c == '\n')
    string[i++] = c;
  string[i] = '\0';
  len = i;

  
  
  /* All the tests to make sure that the methods did what they were suppose to do */
  for (i = 0; string[i] != '\0'; i++){
    printf("Is there a char at position is %d? %s\n", i,
    	   (non_space_char(string[i]) == 1) ? "Yes" : "No");
     printf("Is there a white space at position is %d? %s\n", i,
    (space_char(string[i]) == 1) ? "Yes" : "No");
  }

  printf("There's a word that starts with '%c' ", word_start(string));
  printf("and that word ends with '%c'\n", word_terminator(string));
  printf("This string contains %d words\n", count_words(string));
  duplicate = copy_str(string, len);
  printf("Copied string %s.\nHere's the new copied string: %s\n", string, duplicate); 
  printf("Let's free that copied string.\n");
  free(duplicate);
  printf("Trying to print copied string: %s\n", duplicate);

  printf("The first char of the first word in string is %c.\n", word_start(string));
  printf("The last char of the first word in string is %c.\n", word_terminator(string));
  printf("The # of chars is %d.\n", word_terminator(string)-word_start(string));
  tokenize(string);
  print_tokens(tokens);
  //free_tokens(tokens);

  history = init_history();
  add_history(history, string);
  add_history(history, "I guess that's over.\n");
  add_history(history, "Just kidding! Here's more strings fo' yo' history!\n");
  print_history(history);
  free_history(history);
  print_history(history);
  
  return 0;
}
