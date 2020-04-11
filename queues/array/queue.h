#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

struct queue {
    int head;
    int tail;
    int size;
    int *queue;
};

typedef struct queue queue;

queue *initQueue();
void enqueue(queue *q, int data);
int dequeue(queue *q);
bool empty(queue *q);
bool full(queue *q);

#endif