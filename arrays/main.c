#include <stdio.h>
#include "vector.h"

int main() {
    vector v = initVector(10);
    vector t = initVector(0);

    printf("0: %d, size: %d, capacity: %d, isEmpty: %d\n", v.array[0], size(&v), capacity(&v), isEmpty(&v));
    printf("0: %d, size: %d, capacity: %d, isEmpty: %d\n", t.array[0], size(&t), capacity(&t), isEmpty(&t));

    return 0;
}