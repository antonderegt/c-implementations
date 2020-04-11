#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

struct queue {
    struct queueNode *head;
    struct queueNode *tail;
};

struct queueNode {
    int data;
    struct queueNode *next;
};

typedef struct queue queue;
typedef struct queueNode queueNode;

queue *initQueue();
void enqueue(queue *q, int data);
int dequeue(queue *q);
bool empty(queue *q);

#endif