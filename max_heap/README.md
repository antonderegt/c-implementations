# Implements Max Heap

## How to run: 
```
cc main.c max_heap.c && ./a.out
```

## Functionality
- [X] insert
- [X] sift_up - needed for insert
- [X] get_max - returns the max item, without removing it
- [X] get_size() - return number of elements stored
- [X] is_empty() - returns true if heap contains no elements
- [X] extract_max - returns the max item, removing it
- [X] sift_down - needed for extract_max
- [X] remove(i) - removes item at index x
- [X] heapify - create a heap from an array of elements, needed for heap_sort
- [X] heap_sort() - take an unsorted array and turn it into a sorted array in-place using a max heap
    - note: using a min heap instead would save operations, but double the space needed (cannot do in-place).

