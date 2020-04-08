#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linkedList {
    int item;
    struct linkedList *next;
};

typedef struct linkedList linkedList;

#endif