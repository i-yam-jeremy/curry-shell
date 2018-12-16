#include "list.h"

#include <stdlib.h>

List* List_new() {
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void List_push(List *list, void *value) {
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  node->value = value;
  node->next = list->head;
  list->head = node;
}

void* List_pop(List *list) {
  if (list->head == NULL) {
    return NULL;
  }

  void *value = list->head->value;
  ListNode *next = list->head->next;

  free(list->head);
  list->head = next;

  return value;
}

int List_is_empty(List *list) {
  return list->head == NULL;
}
