#include <stdio.h>
#include "hash_table.h"
#include <assert.h>

int main() {

    hashTable *h = initHashTable();

    // Add key value pair to hash table
    add(h, "Stad", "Ams");

    // Add to same key with different data
    add(h, "Stad", "Amsterdam");
    
    // Add key with same hash value
    add(h, "Ruad", "Rotterdam");

    assert(exists(h, "Stad") == true);
    assert(exists(h, "Ruad") == true);
    assert(exists(h, "City") == false);

    assert(strcmp(get(h, "Stad"), "Amsterdam") == 0);
    assert(strcmp(get(h, "Ruad"), "Rotterdam") == 0);

    removeNode(h, "Stad");
    // Ruad has the same hash value as Stad, so it's index was incremented. 
    // After removing Stad it's value is set to "". 
    // So the remove function knows the key was used before and will continue to look for Ruad.
    removeNode(h, "Ruad");

    assert(exists(h, "Stad") == false);
    assert(exists(h, "Ruad") == false);

    return 0;
}