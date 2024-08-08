#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  int data;
  struct Node* next;
};

struct List {
  struct Node* head;

  int size;
};

struct List* newList();
struct List* prepend();
struct List* append();

#endif