#include <stdio.h>
#include <assert.h>
#include "max_heap.h"

int main() {
    int heap[100];
    heap[0] = 0;

    insert(heap, 5);
    insert(heap, 9);
    insert(heap, 1);
    insert(heap, 2);
    insert(heap, 15);

    print_heap(heap);

    assert(get_max(heap) == 15);
    return 0;
}