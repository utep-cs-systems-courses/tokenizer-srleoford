#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

int hItems = 0;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* newList = (List *) malloc(sizeof(List));

  newList->root = NULL;

  return newList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *newItem = (Item*) malloc(sizeof(struct s_Item));

  newItem->id = ++hItems;
  newItem->str = copy_str(str, strlen(str));
  newItem->next = NULL;

  Item *curr = list->root;

  if (curr == NULL)
    list->root = newItem;
  else {
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = newItem;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *curr = list->root;

  while (curr != NULL){
    if (curr->id == id)
      return curr->str;
    else {
      curr = curr->next;
    }
  }
  return NULL;
}

/* Print the entire contents of the list. */
void print_history(List *list){
  Item* curr = list->root;
  
  while (curr != NULL){
    printf("Entry %d: %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list){
  Item *curr = list->root;
  while (curr != NULL){
    list->root = curr;
    curr = curr->next;
    free(list->root->str);
    free(list->root);
  }
  hItems = 0;
}

#endif
