#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdbool.h>

void insert(int* heap, int value);
void sift_up(int* heap, int index); // needed for insert
void print_heap(int* heap);
int get_max(int* heap); // returns the max item, without removing it
int get_size(int* heap); // return number of elements stored
bool is_empty(int* heap); // returns true if heap contains no elements
int extract_max(int* heap); // returns the max item, removing it
void sift_down(); // needed for extract_max
void remove_node(int* heap, int index); // removes item at index x
void heapify(int* heap, int* arr, int arrSize); // create a heap from an array of elements, needed for heap_sort
void heap_sort(int* unsorted, int* sorted, int size); // take an unsorted array and turn it into a sorted array in-place using a max heap
            // note: using a min heap instead would save operations, but double the space needed (cannot do in-place).


#endif