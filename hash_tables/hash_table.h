#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include <stdlib.h>

struct hashNode {
    int key;
    int value;
};

struct hashTable {
    struct hashNode **data;
    int size;
};

typedef struct hashNode hashNode;
typedef struct hashTable hashTable;

hashTable *initHashTable();
int hash(int key, int size);
void add(hashTable *h, int key, int value);
bool exists(hashTable *h, int key);
int get(hashTable *h, int key);
void removeNode(hashTable *h, int key);

#endif