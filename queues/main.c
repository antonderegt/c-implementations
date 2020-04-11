#include <stdio.h>
#include "queue.h"

int main() {
    queue *q = initQueue();

    enqueue(q, 0);
    enqueue(q, 1);
    enqueue(q, 2);

    // printf("q->tail: %d\n", q->tail->data);
    // printf("q->head: %d\n", q->head->data);

    printf("%d\n", dequeue(q));
    // printf("q->head: %d\n", q->head->data);
    printf("%d\n", dequeue(q));

    return 0;
}