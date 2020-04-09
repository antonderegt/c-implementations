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

#endif