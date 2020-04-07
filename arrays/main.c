#include <stdio.h>
#include "vector.h"

int main() {
    vector v = initVector(10);

    printf("at: %d, size: %d, capacity: %d, isEmpty: %d\n", at(&v, 0), size(&v), capacity(&v), isEmpty(&v));

    return 0;
}