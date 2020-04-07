#include <stdio.h>
#include "vector.h"

int main() {
    struct vector v;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    initVector(&v, arr, 10);

    printf("0: %d, size: %d\n", v.array[0], size(&v));

    return 0;
}