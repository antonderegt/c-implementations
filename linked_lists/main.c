#include "linked_list.h"
#include <stdio.h>
#include <assert.h>

int main() {
    linkedList *head = initLinkedList();
    assert(isEmpty(head) == 1);
    assert(size(head) == 0);

    for(int i = 0; i < 100; i++) {
        push_front(head, i);
    }
    assert(size(head) == 100);

    int val = value_at(head, 0);
    assert(val == 99);
    val = value_at(head, 100);
    assert(val == -1);

    return 0;
}