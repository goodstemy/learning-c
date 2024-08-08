#include <stdio.h>
#include "linked-list.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

int testInit() {
  struct List* list = newList();

  if (list == NULL) {
    return 1;
  }

  return 0;
}

int testAppend(int n) {
  struct List* list = newList();
  int numbers[n];

  for (int i = 0; i < n; i++) {
    list = append(i, list);
    numbers[i] = i;

    printf("%d %d\n", i, list->size);
  }

  struct Node* head = list->head;
  int i = 0;

  while(head != NULL) {
    if (numbers[i] != head->data) {
      return 1;
    }

    head = head->next;
    i++;
  }

  return 0;
}

int main() {
  if (testInit()) {
    printf(ANSI_COLOR_RED "testInit() Failed!" ANSI_COLOR_RED "\n");
    return 1;
  }

  printf(ANSI_COLOR_GREEN "testInit() Success!" ANSI_COLOR_GREEN "\n");

  if (testAppend(100)) {
    printf(ANSI_COLOR_RED "testAppend(n) Failed!" ANSI_COLOR_RED "\n");
    return 1;
  }

  printf(ANSI_COLOR_GREEN "testAppend(n) Success!" ANSI_COLOR_GREEN "\n");

  return 0;
}