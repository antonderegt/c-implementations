#include <stdio.h>
#include "queue.h"

queue *initQueue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->size = 4;
    q->queue = (int*) malloc(q->size * sizeof(int));
    return q;
}

void enqueue(queue *q, int data) {
    if(q->tail + 1 == q->head || q->tail + 1 - q->size == q->head) {
        printf("Cannot overwrite elements\n");
        exit(EXIT_FAILURE);
    }
    q->queue[q->tail] = data;
    q->tail = q->tail == q->size ? 0 : q->tail + 1;
}

int dequeue(queue *q) {
    if(q->head == q->tail) {
        printf("Already dequeued last item\n");
        exit(EXIT_FAILURE);
    }
    int val = q->queue[q->head];
    q->head = q->head == q->size ? 0 : q->head + 1;
    return val;
}

bool empty(queue *q) {
    return q->head == q->tail;
}

bool full(queue *q) {
    return q->tail + 1 == q->head;
}