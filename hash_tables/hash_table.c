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
    int index = hash(key, h->size);
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            printf("Same key, new value\n");
            strcpy(h->data[index]->value, value);
            return;
        }
        index++;
    }
    hashNode *newNode = (hashNode*) malloc(sizeof(hashNode));
    newNode->key = (char *) malloc(100 * sizeof(char));
    newNode->value = (char *) malloc(100 * sizeof(char));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    h->data[index] = newNode;
}

bool exists(hashTable *h, char* key) {
    int index = hash(key, h->size);

    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            return true;
        }
        index++;
    }

    return false;
}

char* get(hashTable *h, char* key) {
    int index = hash(key, h->size);
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            return h->data[index]->value;
        }
        index++;
    }
    return "";
}

void removeNode(hashTable *h, char* key) {
    int index = hash(key, h->size);
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            printf("Found key %s, removing value %s.\n", h->data[index]->key, h->data[index]->value);
            free(h->data[index]->key);
            free(h->data[index]->value);
            h->data[index]->key = "";
            h->data[index]->value = "";
            int i = 1;
            while(h->data[index + i] != NULL) {
                if(index == hash(h->data[index + i]->key, h->size)) {
                    h->data[index] = h->data[index + i];
                    printf("Found another key %s, shifting value %s.\n", h->data[index + i]->key, h->data[index + i]->value);
                    free(h->data[index + i]->key);
                    free(h->data[index + i]->value);
                    h->data[index + i]->key = "";
                    h->data[index + i]->value = "";
                    i++;
                } else {
                    break;
                }    
            }
        }
        index++;
    }
}