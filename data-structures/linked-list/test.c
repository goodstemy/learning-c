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

int testPrepend(int n) {
  struct List* list = newList();
  int numbers[n];

  for (int i = n - 1; i >= 0; i--) {
    list = prepend(i, list);
    numbers[i] = i;
  }

  struct Node* head = list->head;
  int i = n - 1;

  while(head != NULL) {
    if (numbers[i] != head->data) {
      return 1;
    }

    head = head->next;
    i--;
  }

  return 0; 
}

int testAppendAt(int size, int at) {
  struct List* list = newList();

  int numbers[size];

  for (int i = 0; i < size - 1; i++) {
    list = append(i, list);
    numbers[i] = i;
  }

  int data = size * 2;
  list = appendAt(data, at, list);

  struct Node* node = list->head->next;

  int n = 1;
  while(n != at) {
    node = node->next;

    n++;
  }

  if (node->data != data) {
    return 1;
  }

  return 0;
}

int testDeleteAt(int at) {
  struct List* list = newList();

  int size = 100;
  int numbers[size];

  for (int i = 0; i < size - 1; i++) {
    list = append(i, list);
    numbers[i] = i;
  }

  int data = size * 2;
  list = deleteAt(at, list);

  struct Node* node = list->head->next;

  int n = 0;
  while(n < list->size-1) {
    node = node->next;

    if (!node) {
      break;
    }

    if (node->data == data) {
      return 1;
    }
    n++;
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

  if (testPrepend(1)) {
    printf(ANSI_COLOR_RED "testPrepend(n) Failed!" ANSI_COLOR_RED "\n");
    return 1;
  }

  printf(ANSI_COLOR_GREEN "testPrepend(n) Success!" ANSI_COLOR_GREEN "\n");

  if (testAppendAt(100, 4)) {
    printf(ANSI_COLOR_RED "testAppendAt(n, at) Failed!" ANSI_COLOR_RED "\n");
    return 1;
  }

  printf(ANSI_COLOR_GREEN "testAppendAt(n, at) Success!" ANSI_COLOR_GREEN "\n");

   if (testDeleteAt(4)) {
    printf(ANSI_COLOR_RED "testDeleteAt(at) Failed!" ANSI_COLOR_RED "\n");
    return 1;
  }

  printf(ANSI_COLOR_GREEN "testDeleteAt(at) Success!" ANSI_COLOR_GREEN "\n");

  return 0;
}