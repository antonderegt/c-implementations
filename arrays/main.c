#include <stdio.h>
#include "vector.h"

int main() {
    vector v = initVector(10);
    vector t = initVector(0);

    printf("0: %d, size: %d, capacity: %d\n", v.array[0], size(&v), capacity(&v));

    printf("0: %d, size: %d, capacity: %d\n", t.array[0], size(&t), capacity(&t));

    return 0;
}