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

struct List* appendAt(int data, int at, struct List* list) {
  if (at > list->size) {
    printf("Error: Append at N > size.");
    return list;
  }

  if (at < 0) {
    printf("Error: Append at N < 0.");
    return list;
  }

  if (at == 0) {
    return prepend(data, list);
  }

  if (at == list->size) {
    return append(data, list);
  }

  struct Node* prevNode = list->head;
  struct Node* node = list->head;

  int n = 1;
  while(n != at) {
    prevNode = node;
    node = node->next;

    n++;
  }

  struct Node* newNode;

  newNode = (struct Node*) malloc(sizeof(*newNode));
  newNode->data = data;
  newNode->next = prevNode->next;

  node->next = newNode;

  return list;
}

struct List* deleteAt(int at, struct List* list) {
  if (at > list->size) {
    printf("Error: Delete at N > size.");
    return list;
  }

  if (at < 0) {
    printf("Error: Delete at N < 0.");
    return list;
  }

  if (at == 0) {
    list->head = list->head->next;
    return 0;
  }

  struct Node* prevNode = list->head;
  struct Node* nextNode = list->head->next;

  int n = 1;
  while(n != at) {
    prevNode = prevNode->next;
    nextNode = nextNode->next;

    n++;
  }

  prevNode->next = nextNode->next;
  list->size--;
  return list;
}
