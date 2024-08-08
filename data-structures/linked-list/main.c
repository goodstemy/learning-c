#include <stdio.h>
#include "linked-list.h"

int main() {
  // struct Test* test = newTest(1);

  // printf("%d -- 1\n", test->data);
  // printf("%d -- 2\n", test->innerTest->anotherData);
  // int data = &test;

  // printf("%d", &);

  // printf("++4\n");

  struct List* list = newList();
  
  // list = append(2, list);
  // list = append(3, list);

  // printf("%d", list->head->data);
  // printf("%d", list->head->next->data);
  // printf("%d", list->head->next->next->data);
  // printf("%d", list->head->next->next->next->data);

  for (int i = 0; i < 100; i++) {
    list = append(i, list);

    printf("%d %d\n", i, list->size);
  }

  printf("-----------\n");

  struct Node* head = list->head;

  while(head != NULL) {
    printf("%d ++", head->data);

    head = head->next;
  }

  // for (int i = 0; i < 100; i++) {
  //   printf("%d \n", head->data);

  //   // head = head->next;
  // }

  return 0;
}