#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    int *array;
    int size;
    int capacity;
};

typedef struct vector vector;

void initVector(vector *v, int *array, int arrSize);

int size(vector *v);

int capacity(vector *v);

#endif