#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct hashNode {
    char* key;
    char* value;
};

struct hashTable {
    struct hashNode **data;
    int size;
};

typedef struct hashNode hashNode;
typedef struct hashTable hashTable;

hashTable *initHashTable();
int hash(char* key, int size);
void add(hashTable *h, char* key, char* value);
bool exists(hashTable *h, char* key);
char* get(hashTable *h, char* key);
void removeNode(hashTable *h, char* key);

#endif