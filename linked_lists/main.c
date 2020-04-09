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

    val = pop_front(head);
    assert(val == 99);
    assert(size(head) == 99);

    push_back(head, 100);
    assert(size(head) == 100);
    
    val = pop_back(head);
    assert(val == 100);

    val = front(head);
    assert(val == 98);

    val = back(head);
    assert(val == 0);

    insert_after(head, 50, 111);
    assert(value_at(head, 50) == 111);

    printList(head);
    return 0;
}