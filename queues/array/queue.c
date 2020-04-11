#include <stdio.h>
#include "queue.h"

queue *initQueue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->size = 16;
    q->queue = (int*) malloc(q->size * sizeof(int));
    return q;
}

void enqueue(queue *q, int data) {
    q->queue[q->tail] = data;
    q->tail = q->tail == q->size ? 0 : q->tail + 1;
}

int dequeue(queue *q) {
    int val = q->queue[q->head];
    q->head = q->head == q->size ? 0 : q->head + 1;
    return val;
}

bool empty(queue *q) {
    return q->head == q->tail;
}