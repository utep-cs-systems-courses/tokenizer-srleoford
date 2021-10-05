#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

enum boolean {NO, YES};

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if (c == '\0')
    return NO;
  else if (c == ' ' || c == '\t' || c == '\n')
    return YES;
  else
    return NO;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if (c == '\0')
    return NO;
  else if (c == ' ' || c == '\t' || c == '\n')
    return NO;
  else
    return YES;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  int i;

  for (i = space_char(str[0]) == YES ? 1 : 0;
       space_char(str[i]) == YES; ++i)
    ;
  
  return str+i;
} 

/* Returns a pointer end char following *word */
char *word_end(char *word){
  int i;
  
  for (i = space_char(word[0] == YES) ? 1 : 0;	/* When pointer is on a space char after word */
       non_space_char(word[i]) == YES; ++i)
    ;

  return word+i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int i;
  int inWord = NO;
  int words = 0;

  for (i = space_char(str[0] == YES) ? 1 : 0;	/* When pointer is on a space char after word */
       str[i] != '\0'; ++i)
    if (space_char(str[i]) == YES)
      inWord = NO;
    else if (inWord == NO){
      inWord = YES;
      words++;
    }
  return words;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *duplicate = malloc(sizeof(inStr));
  int i;

  for (i = 0; inStr[i] != '\0' && i < len; ++i)
    duplicate[i] = inStr[i];
  duplicate[i+1] = '\0';
  
  return duplicate;
}

void freeStr(char *copy){
  free(copy);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int i;
  char *wordp;
  char *nextwordp;
  char *tokens[count_words(str)];

  for (i = 0, wordp = str; i < count_words(str); i++){	/* For every word in the original string */
    wordp = word_start(wordp);
    nextwordp = word_end(wordp);
    *(tokens+i) = copy_str(wordp, nextwordp-wordp);
    printf("Successfully copied token %s from string, which is %d chars long\n", *(tokens+i), nextwordp-wordp);
    wordp = nextwordp;
  }

  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i;
  
  for (i = 0; tokens+i != NULL; i++)
    printf("%s\n", *(tokens+i));
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens);

int main(){
  int i;
  char* string = "Hello world! Look!!! My beautiful wife is checking out my work! Isn't she amazing?!";
  char* duplicate;

  printf("%s\n\n", string);
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
  char **tokens = tokenize(string);
  printf("%s\n", *(tokens[0]));
  
  return 0;
}
