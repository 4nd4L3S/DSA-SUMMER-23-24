#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackLL.h"

void initStack(StackLinkedList *s) {
    s->top = NULL;
}

StackLinkedList createStack() {
    StackLinkedList s;
    s.top = NULL;
    return s;
}

bool isEmpty(StackLinkedList *s) {
    return (s->top == NULL);
}

void stack_push(StackLinkedList *s, int elem) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = elem;
    newNode->next = s->top;
    s->top = newNode;
}

bool stack_pop(StackLinkedList *s) {
	
    if (isEmpty(s)) {
        printf("STACK IS EMPTY\n");
        return false;
    }
    
    StackNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    
    return true;
}

int stack_peek(StackLinkedList *s) {
    printf("PEEK: %d \n", s->top->data);
    
    return s->top->data;
}

void display(StackLinkedList *s) {
    StackNode *current = s->top;
    printf("STACK CONTENTS:\n");
    
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void visualize(StackLinkedList *s) {
    StackNode *current = s->top;
    int index = 0;
    printf("DATA - NODE\n");
    while (current != NULL) {
        printf("%d      %d\n", current->data, index++);
        current = current->next;
    }
}
