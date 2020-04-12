#include <stdio.h>
#include "hash_table.h"

hashTable *initHashTable() {
    hashTable *hashTable = malloc(sizeof(hashTable));
    hashTable->size = 999;
    hashTable->data = malloc(hashTable->size * sizeof(hashNode));

    return hashTable;
}

int hash(int key, int size) {
    return key % size;
}

void add(hashTable *h, int key, int value) {
    hashNode *newNode = (hashNode *) malloc(sizeof(hashNode));
    newNode->key = key;
    newNode->value = value;
    *(h->data + hash(key, h->size)) = newNode;
}

bool exists(hashTable *h, int key) {
    bool exists = false;
    int index = hash(key, h->size);
    hashNode *get = *(h->data + hash(key, h->size));
    if(get != NULL && get->key == key) {
        exists = true;
        printf("Exists: %d\n",get->value);
    }
    return exists;
}

int get(hashTable *h, int key) {
    hashNode *get = *(h->data + hash(key, h->size));

    if(get->key == key) {
        return get->value;
    }
    return -1;
}

void removeNode(hashTable *h, int key) {
    int index = hash(key, h->size);
    hashNode *get = *(h->data + index);

    if(get->key == key) {
        printf("Found key %d, removing value %d.\n", get->key, get->value);
        free(h->data[index]);
        h->data[index]->key = 0;
        h->data[index]->value = 0;
    }
}