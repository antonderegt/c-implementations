#include <stdio.h>
#include "queue.h"
#include <assert.h>

int main() {
    queue *q = initQueue();
    assert(empty(q) == true);

    enqueue(q, 0);
    enqueue(q, 1);
    enqueue(q, 2);

    assert(dequeue(q) == 0);
    assert(dequeue(q) == 1);
    
    enqueue(q, 3);
    enqueue(q, 4);
    
    assert(empty(q) == false);

    assert(dequeue(q) == 2);
    assert(dequeue(q) == 3);
    assert(dequeue(q) == 4);

    assert(empty(q) == true);

    return 0;
}