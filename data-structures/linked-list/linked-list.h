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
struct List* prepend(int, struct List*);
struct List* append(int, struct List*);
struct List* appendAt(int, int, struct List*);

#endif