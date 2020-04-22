# Implements a Hash Table

## How to run:
```
cc main.c hash_table.c && ./a.out
```

## ToDo

- Improve hash function, modding with a prime number works, but is not the best
    - Multiplication Method
    - Universal Hashing

## Functionality

- [X] implement with array using linear probing
    - [X] hash(k, m) - m is size of hash table
    - [X] add(key, value) - if key already exists, update value
    - [X] exists(key)
    - [X] get(key)
    - [X] remove(key)