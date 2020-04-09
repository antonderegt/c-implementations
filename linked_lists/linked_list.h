#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

struct linkedList {
    int item;
    struct linkedList *next;
};

typedef struct linkedList linkedList;

linkedList * initLinkedList();

bool isEmpty(linkedList *head);

int size(linkedList *head);

void push_front(linkedList *head, int item);

int value_at(linkedList *head, int index);

int pop_front(linkedList *head);

void printList(linkedList *head);

void push_back(linkedList *head, int item);

int pop_back(linkedList *head);

int front(linkedList *head);

int back(linkedList *head);

void insert_after(linkedList *head, int index, int item);

void erase(linkedList *head, int index);

#endif