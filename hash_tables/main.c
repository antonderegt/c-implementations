#include <stdio.h>
#include "hash_table.h"
#include <assert.h>

int main() {

    hashTable *h = initHashTable(999);

    // Add key value pair to hash table
    add(h, "Stad", "Ams");

    // Add to same key with different data
    add(h, "Stad", "Amsterdam");
    
    // Add key with same hash value
    add(h, "Ruad", "Rotterdam");
    add(h, "Rubc", "Den Haag");

    assert(exists(h, "Stad") == true);
    assert(exists(h, "Ruad") == true);
    assert(exists(h, "City") == false);

    assert(strcmp(get(h, "Stad"), "Amsterdam") == 0);
    assert(strcmp(get(h, "Ruad"), "Rotterdam") == 0);

    removeNode(h, "Stad");
    removeNode(h, "Ruad");

    assert(exists(h, "Stad") == false);
    assert(exists(h, "Ruad") == false);

    add(h, "Stad", "Amsterdam");
    assert(exists(h, "Stad") == true);

    return 0;
}