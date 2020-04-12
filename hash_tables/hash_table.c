#include <stdio.h>
#include "hash_table.h"

hashTable *initHashTable() {
    hashTable *hashTable = malloc(sizeof(hashTable));
    hashTable->size = 999;
    hashTable->data = malloc(hashTable->size * sizeof(hashNode));

    return hashTable;
}

int hash(char* key, int size) {
    int hashValue = 0, i = 0;
    while(key[i] != '\0') {
        hashValue += key[i++];
    }
    return hashValue % size;
}

void add(hashTable *h, char* key, char* value) {
    hashNode *newNode = (hashNode*) malloc(sizeof(hashNode));
    newNode->key = (char *) malloc(100 * sizeof(char));
    newNode->value = (char *) malloc(100 * sizeof(char));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    int index = hash(key, h->size);
    h->data[index] = newNode;
}

bool exists(hashTable *h, char* key) {
    bool exists = false;
    int index = hash(key, h->size);
    hashNode *get = h->data[index];
    if(get != NULL && strcmp(get->key, key) == 0) {
        exists = true;
        printf("Exists: %d\n",get->value[0]);
    }
    return exists;
}

char* get(hashTable *h, char* key) {
    int index = hash(key, h->size);
    hashNode *get = h->data[index];

    if(strcmp(get->key, key) == 0) {
        return get->value;
    }
    return "";
}

void removeNode(hashTable *h, char* key) {
    int index = hash(key, h->size);
    hashNode *get = h->data[index];

    if(strcmp(get->key, key) == 0) {
        printf("Found key %c, removing value %c.\n", get->key[0], get->value[0]);
        free(h->data[index]->key);
        free(h->data[index]->value);
        h->data[index]->key = "";
        h->data[index]->value = "";
    }
}