#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    int *array;
    int size;
    int capacity;
};

void initVector(struct vector *v, int *array, int arrSize);

int size(struct vector *v);

int capacity(struct vector *v);

#endif