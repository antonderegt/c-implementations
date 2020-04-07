#include <stdio.h>
#include "vector.h"
#include <assert.h>

int main() {
    vector v = initVector(10);
    assert(size(&v) == 0);
    assert(capacity(&v) == 16);
    assert(isEmpty(&v) == 1);
    assert(at(&v, 0) == -1);

    for(int i = 0; i < 20; i++) {
        push(&v, i);
    }
    assert(size(&v) == 20);
    assert(capacity(&v) == 32);
    assert(isEmpty(&v) == 0);
    assert(at(&v, 0) == 0);

    int popValue = pop(&v);
    assert(popValue == 19);
    assert(size(&v) == 19);

    insert(&v, 5, 100);
    assert(at(&v, 5) == 100);
    assert(size(&v) == 20);

    prepend(&v, 99);
    assert(at(&v, 0) == 99);
    assert(size(&v) == 21);

    deleteAt(&v, 5);
    assert(at(&v, 5) != 100);
    assert(size(&v) == 20);

    int foundIndex = find(&v, 99);
    int notFound = find(&v, 100);
    assert(foundIndex == 0);
    assert(notFound == -1);

    push(&v, 88);
    push(&v, 88);
    assert(size(&v) == 22);
    findRemove(&v, 88);
    assert(find(&v, 88) == -1);
    assert(size(&v) == 20);

    printf("at: %d, size: %d, capacity: %d, isEmpty: %d\n", at(&v, 0), size(&v), capacity(&v), isEmpty(&v));

    return 0;
}