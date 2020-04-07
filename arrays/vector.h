#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    int *array;
    int size;
};

void initVector(struct vector *v, int *array, int arrSize);

int size(struct vector *v);

#endif