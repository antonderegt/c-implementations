#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct vector {
    int *array;
    int size;
    int capacity;
};

typedef struct vector vector;

vector *initVector(int arrSize);

int size(vector *v);

int capacity(vector *v);

bool isEmpty(vector *v);

int at(vector *v, int index);

void push(vector *v, int item);

void resize(vector *v, int newCapacity);

int pop(vector *v);

void insert(vector *v, int index, int item);

void prepend(vector *v, int item);

void deleteAt(vector *v, int index);

int find(vector *v, int item);

void findRemove(vector *v, int item);

#endif