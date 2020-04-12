#include <stdio.h>
#include "hash_table.h"
#include <assert.h>

int main() {

    hashTable *h = initHashTable();

    add(h, 1500, 9999);
    add(h, 123456, 123);

    assert(exists(h, 1500) == true);
    assert(exists(h, 1555) == false);

    assert(get(h, 1500) == 9999);

    removeNode(h, 1500);

    assert(exists(h, 1500) == false);

    return 0;
}