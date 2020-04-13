#include <stdio.h>
#include "hash_table.h"

hashTable *initHashTable(int size) {
    hashTable *hashTable = malloc(sizeof(hashTable));
    hashTable->size = size;
    hashTable->data = malloc(size * sizeof(hashNode));

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

    // Check if the index is empty, else increase index with 1
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            strcpy(h->data[index]->value, value);
            return;
        }
        // When a hashNode gets removed it sets the key and value to "",
        // we don't expect the key and value to be empty so we can overwrite
        if(strcmp(h->data[index]->key, "") == 0 && strcmp(h->data[index]->value, "") == 0) {
            break;
        }
        index = (index + 1) % h->size;
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
        index = (index + 1) % h->size;
    }

    return false;
}

char* get(hashTable *h, char* key) {
    int index = hash(key, h->size);
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            return h->data[index]->value;
        }
        index = (index + 1) % h->size;
    }
    return "";
}

void removeNode(hashTable *h, char* key) {
    int index = hash(key, h->size);
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index]->key, key) == 0) {
            free(h->data[index]->key);
            free(h->data[index]->value);
            h->data[index]->key = "";
            h->data[index]->value = "";

            // When a hashNode gets removed we check whether nodes were 
            // shifted to the right to avoid hash collisions,
            // in that case we shift them back to the left
            int incIndex = (index + 1) % h->size;
            while(h->data[incIndex] != NULL) {

                if(index == hash(h->data[incIndex]->key, h->size)) {
                    h->data[index] = h->data[incIndex];
                    free(h->data[incIndex]->key);
                    free(h->data[incIndex]->value);
                    h->data[incIndex]->key = "";
                    h->data[incIndex]->value = "";
                    incIndex = (incIndex + 1) % h->size;
                } else {
                    break;
                }    
            }
        }
        index = (index + 1) % h->size;
    }
}