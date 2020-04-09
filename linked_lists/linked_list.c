#include "linked_list.h"

linkedList *initLinkedList() {
    linkedList *head = (linkedList *) malloc(sizeof(linkedList));
    head->item = 0;
    head->next = NULL;

    return head;
}

bool isEmpty(linkedList *head) {
    if(head->next == NULL) {
        return true;
    }
    return false;
}