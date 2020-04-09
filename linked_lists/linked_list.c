#include <stdio.h>
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

int size(linkedList *head) {
    int size = 0;
    while(head->next != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

void push_front(linkedList *head, int item) {
    linkedList *node = (linkedList *)malloc(sizeof(linkedList));
    node->item = item;
    node->next = head->next;
    head->next = node;
}

int value_at(linkedList *head, int index) {
    for(int i = 0; i <= index; i++) {
        if(head->next == NULL) {
            return -1;
        }
        head = head->next;
    }
    return head->item;
}

int pop_front(linkedList *head) {
    int popValue = head->next->item;
    head->next = head->next->next;
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
    node->item = item;
    node->next = NULL;
    head->next = node; 
}

int pop_back(linkedList *head) {
   linkedList *tempNode = (linkedList *)malloc(sizeof(linkedList));
    while(head->next != NULL) {
        tempNode = head;
        head = head->next;
    }
    tempNode->next = NULL;
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
    head->next = head->next->next;
}