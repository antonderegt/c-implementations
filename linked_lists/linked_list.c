#include <stdio.h>
#include "linked_list.h"

void check_pointer(void *p){
    if(p == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

linkedList *initLinkedList() {
    linkedList *head = (linkedList *) malloc(sizeof(linkedList));
    check_pointer(head);

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

int size(linkedList *head) {
    int size = 0;
    linkedList *currentNode = head;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
        size++;
    }
    return size;
}

void push_front(linkedList *head, int item) {
    linkedList *node = (linkedList *)malloc(sizeof(linkedList));
    check_pointer(node);

    node->item = item;
    node->next = head->next;
    head->next = node;
}

int value_at(linkedList *head, int index) {
    for(int i = 0; i <= index; i++) {
        if(head->next == NULL) {
            printf("Index %d out of bounds.\n", index);
            exit(EXIT_FAILURE);
        }
        head = head->next;
    }
    return head->item;
}

int pop_front(linkedList *head) {
    if(head->next == NULL) {
        printf("List already empty\n");
        exit(EXIT_FAILURE);
    }
    linkedList *temp = head->next;
    int popValue = temp->item;
    head->next = head->next->next;
    free(temp);
    return popValue;
}

void printList(linkedList *head) {
    while(head->next != NULL) {
        head = head->next;
        printf("%d -> ", head->item);
    }
    printf("\n");
}

void push_back(linkedList *head, int item) {
    while(head->next != NULL){
        head = head->next;
    }
    linkedList *node = (linkedList *)malloc(sizeof(linkedList));
    check_pointer(node);
    node->item = item;
    node->next = NULL;
    head->next = node; 
}

int pop_back(linkedList *head) {
   linkedList *prevNode;
    while(head->next != NULL) {
        prevNode = head;
        head = head->next;
    }
    free(prevNode->next);
    prevNode->next = NULL;
    return head->item;
}

int front(linkedList *head) {
    return head->next->item;
}

int back(linkedList *head) {
    while(head->next != NULL) {
        head = head->next;
    }
    return head->item;
}

void insert_after(linkedList *head, int index, int item) {
    for(int i = 0; i < index; i++) {
        if(head->next == NULL) {
            return;
        }
        head = head->next;
    }
    linkedList *newNode = (linkedList *)malloc(sizeof(linkedList)); 
    newNode->item = item;
    newNode->next = head->next;
    head->next = newNode;
}

void erase(linkedList *head, int index) {
    for(int i = 0; i < index; i++) {
        if(head->next == NULL) {
            return;
        }
        head = head->next;
    }
    linkedList *tempNode = head->next;
    head->next = tempNode->next;
    free(tempNode);
}

int value_n_from_end(linkedList *head, int n) {
    if(n > 0) {
        return get_node_at(head, size(head)-n)->item;
    }
    return -1;
}

linkedList *get_node_at(linkedList *head, int index) {
   for(int i = 0; i < index; i++) {
            head = head->next;
    }
    return head; 
}

void reverse(linkedList *head) {
    linkedList *prevNode = NULL;
    linkedList *currentNode = head->next;
    linkedList *nextNode;

    while(currentNode) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
    }
    head->next = prevNode;
}

void remove_value(linkedList *head, int item) {
    linkedList *currentNode = head;
    linkedList *prevNode;

    while (currentNode->next != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;

        if(currentNode->item == item) {
            prevNode->next = currentNode->next;
            free(currentNode);
            break;
        }
    }
    
}