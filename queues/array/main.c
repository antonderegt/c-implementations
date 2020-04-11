#include <stdio.h>
#include "queue.h"
#include <assert.h>

int main() {
    queue *q = initQueue();
    assert(empty(q) == true);

    enqueue(q, 0);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    assert(empty(q) == false);

    assert(dequeue(q) == 0);
    assert(dequeue(q) == 1);

    return 0;
}