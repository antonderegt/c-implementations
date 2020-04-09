#include "linked_list.h"
#include <stdio.h>
#include <assert.h>

int main() {
    linkedList *head = initLinkedList();
    assert(isEmpty(head) == 1);
    assert(size(head) == 0);

    return 0;
}