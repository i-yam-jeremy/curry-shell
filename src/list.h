#ifndef __LIST_H__
#define __LIST_H__

typedef struct list_node {
  void *value;
  struct list_node *next;
} ListNode;

typedef struct {
  ListNode *head;
} List;

List* List_new();
void List_push(List *list, void *value);
void* List_pop(List *list);
int List_is_empty(List *list);

#endif
