#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    int *array;
};

void initVector(struct vector *v, int *array, int arrSize);

#endif