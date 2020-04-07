#include <stdio.h>
#include "vector.h"

int main() {
    struct vector v;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    initVector(&v, arr, 10);

    printf("0: %d, 10: %d\n", v.array[0], v.array[10]);

    return 0;
}