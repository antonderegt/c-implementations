# Implements a Vector

## How to run: 
```
cc main.c vector.c && ./a.out
```

## Functionality
    - [X] new raw data array with allocated memory
        - can allocate int array under the hood, just not use its features
        - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
    - [ ] size() - number of items
    - [ ] capacity() - number of items it can hold
    - [ ] is_empty()
    - [ ] at(index) - returns item at given index, blows up if index out of bounds
    - [ ] push(item)
    - [ ] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - [ ] prepend(item) - can use insert above at index 0
    - [ ] pop() - remove from end, return value
    - [ ] delete(index) - delete item at index, shifting all trailing elements left
    - [ ] remove(item) - looks for value and removes index holding it (even if in multiple places)
    - [ ] find(item) - looks for value and returns first index with that value, -1 if not found
    - [ ] resize(new_capacity) // private function
        - when you reach capacity, resize to double the size
        - when popping an item, if size is 1/4 of capacity, resize to half