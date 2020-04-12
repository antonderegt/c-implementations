#include <stdio.h>
#include "hash_table.h"
#include <assert.h>

int main() {

    hashTable *h = initHashTable();

    add(h, "Stad", "Amsterdam");
    add(h, "Straat", "Nassaukade");

    assert(exists(h, "Stad") == true);
    assert(exists(h, "City") == false);

    assert(strcmp(get(h, "Stad"), "Amsterdam") == 0);

    removeNode(h, "Stad");

    assert(exists(h, "Stad") == false);

    return 0;
}