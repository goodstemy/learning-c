#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct List {
  struct Node* head;

  int size;
};

struct List* newList() {
  struct List* list;

  list = (struct List*) malloc(sizeof(*list));

  return list;
};

struct List* prepend(int data, struct List* list) {
  struct Node* newHead;
  struct Node* oldHead = list->head;

  newHead = (struct Node*) malloc(sizeof(*newHead));
  newHead->data = data;

  // on first element
  if (oldHead == NULL) {
    list->head = newHead;

    list->size++;
    return list;
  }

  // on N element
  newHead->next = list->head;
  list->head = newHead;

  return list;
}

struct List* append(int data, struct List* list) {
  struct Node* nextHead;
  struct Node* currentHead = list->head;

  nextHead = (struct Node*) malloc(sizeof(*nextHead));
  nextHead->data = data;

  // on first element
  if (currentHead == NULL) {
    list->head = nextHead;

    list->size++;
    return list;
  }

  struct Node* lastNode = currentHead->next;

  // on second element
  if (lastNode == NULL) {
    currentHead->next = nextHead;

    list->size++;
    return list;
  }

  // on N element
  while(1) {
    if (lastNode->next == NULL) {
      break;
    }

    lastNode = lastNode->next;
  }

  lastNode->next = nextHead;

  list->size++;
  return list;
}
