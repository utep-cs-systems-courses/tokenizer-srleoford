#include <stdio.h>
#include <stdlib.h>

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

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* temp;

  temp->root->id = 0;
  temp->root->str = "Temporary String";
  temp->root->next = NULL;

  return temp;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  int i;
  Item *temp;
  
  printf("About to traverse through the list...\n");
  printf("temp is %d\n", list->root->id);
  for (i = 0, temp = list->root; temp != NULL; temp = temp->next, i++)
    printf("Checking %d Item in the list\n", i);
  printf("ID for new Item is %d\n", i);
  
  temp->id = i;
  temp->str = str;
  temp->next = NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/* Print the entire contents of the list. */
void print_history(List *list);

/* Free the history list and the strings it references. */
void free_history(List *list);

#endif
