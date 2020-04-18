#include <stdio.h>
#include <assert.h>
#include "max_heap.h"

int main() {
    int heap[100];
    heap[0] = 0;
    assert(is_empty(heap) == true);

    insert(heap, 5);
    insert(heap, 9);
    insert(heap, 1);
    insert(heap, 2);
    insert(heap, 15);

    print_heap(heap);

    remove_node(heap, 2);
    assert(get_size(heap) == 4);
    print_heap(heap);

    assert(get_max(heap) == 15);
    assert(get_size(heap) == 4);
    assert(is_empty(heap) == false);

    assert(get_size(heap) == 4);
    assert(extract_max(heap) == 15);
    assert(get_size(heap) == 3);

    int unsorted[] = {12, 34, 13, 8, 5, 20, 11};
    int newHeap[100];
    newHeap[0] = 0;
    heapify(newHeap, unsorted, 7);
    print_heap(newHeap);

    int sorted[7];
    heap_sort(unsorted, sorted, 7);

    printf("\nSorted array:\n");
    for(int i = 0; i < 7; i++) {
        printf("%d\t", sorted[i]);
    }
    printf("\n");

    return 0;
}