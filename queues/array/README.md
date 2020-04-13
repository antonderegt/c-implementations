# Implements a Queue with an Array

## How to run:
```
cc main.c queue.c && ./a.out
```

## Functionality

- [X] Implement using fixed-sized array:
    - [X] enqueue(value) - adds item at end of available storage
    - [X] dequeue() - returns value and removes least recently added element
    - [X] empty()
    - [X] full()

- [X] Cost:
    - a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n) because you'd need the next to last element, causing a full traversal each dequeue
    - enqueue: O(1) (amortized, linked list and array [probing])
    - dequeue: O(1) (linked list and array)
    - empty: O(1) (linked list and array)
