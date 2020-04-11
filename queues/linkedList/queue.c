#include <stdio.h>
#include "queue.h"

queue *initQueue() {
    queue *q = (queue*) malloc(sizeof(queue));
    return q;
}

void enqueue(queue *q, int data) {
    queueNode *newNode = (queueNode*) malloc(sizeof(queueNode));
    if(q->head == NULL) {
        q->head = newNode;
        q->tail = newNode;
    }
    q->tail->next = newNode;
    q->tail = newNode;
    newNode->data = data;
}

int dequeue(queue *q) {
    int val = -1;
    if(q->head != NULL) {
        queueNode *d = q->head;
        val = d->data;

        if(d->next != NULL) {
            q->head = d->next;
        }

        free(d);
    }

    return val;
}

bool empty(queue *q) {
    return !q->head;
}