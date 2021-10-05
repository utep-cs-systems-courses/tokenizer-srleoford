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

List *history;
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

  List *curr = list;
  if (curr->root == NULL)
    curr->root = newItem;
  else {
    while (curr->root->next != NULL)
      curr->root = curr->root->next;
    curr->root->next = newItem;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  printf("Traversing through list...\n");
  List *curr = list;

  while (curr->root != NULL){
    printf("Current value is %d\n", curr->root->id);
    printf("Current string is %s\n", curr->root->str);
    if (curr->root->id == id)
      return curr->root->str;
    else {
      printf("Item %d doesn't match Item %d\n", id, curr->root->id);
      curr->root = curr->root->next;
    }
  }
  printf("Item %d isn't in history\n", id);
  return NULL;
}

/* Print the entire contents of the list. */
void print_history(List *list){
  while (list->root != NULL){
    printf("Entry %d: %s\n", list->root->id+1, list->root->str);
    list->root = list->root->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list);

#endif
