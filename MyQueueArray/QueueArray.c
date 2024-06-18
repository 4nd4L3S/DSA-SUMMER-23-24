#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "QueueArray.h"

void InitQ(Queue *head){
	head->front=1;
	head->rear=0;
}

bool isEmpty(Queue head){
	return ((head.rear+1)%MAX==head.front)? true:false;
}

bool isFull(Queue head){
	return ((head.rear+2)%MAX==head.front)? true:false;
}

void Enqueue(Queue *head, int x){
	if(isFull(*head)!=true){
		head->rear=(head->rear+1)%MAX;
		head->elem[head->rear]=x;
	}else {
        printf("Queue is empty. Cannot Enqueue.\n");
    }
}

void Dequeue(Queue *head){
	if(isEmpty(*head)!=true){
		head->front=(head->front+1)%MAX;
	}else {
        printf("Queue is full. Cannot Dequeue %d.\n");
    }
}

void Display(Queue head){
	if (isEmpty(head)) {
        printf("Queue is empty.\n");
    } else {
    	
		int i = head.front;
	    
	    printf("Queue elements: ");
	    while (i != (head.rear + 1) % MAX) {
	        printf("%d ", head.elem[i]);
	        i = (i + 1) % MAX;
	    }
	    printf("\n");
	}
}
