#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "QueueLL.h"


void InitQ(Queue *head){
	head->rear = NULL;
	head->front = NULL;
}

bool isEmpty(Queue head){
	return head.front == NULL ? true:false;
}

void Enqueue(Queue *head, int x){
	Nodeptr temp;
    temp = (Nodeptr)malloc(sizeof(Node));

    if (temp != NULL) {
    	temp->elem = x;
        temp->link = NULL;
        
        if (isEmpty(*head)) {
            head->front = head->rear = temp;
            
        } else {
            head->rear->link = temp;
            head->rear = temp;
            
        }
    }
	
}

void Dequeue(Queue *head){
	Nodeptr temp = head->front; 
	
	if(isEmpty(*head)){
		printf("QUEUE IS EMPTY");
		return;
	}
	
	printf("Dequeue: %d \n", temp->elem);
	head->front = head->front->link;
	
	if (head->front == NULL) {
		head->rear = NULL;
	}
	
	free(temp);	
	
}


void Display(Queue head){
	Nodeptr temp=head.front;
	
	if(isEmpty(head)){
		printf("QUEUE IS EMPTY\n");
		return;
	}
	printf("Queue: ");
	while(temp!=NULL){
		printf("%d  ", temp->elem);
		temp=temp->link;
	}
	printf("\n");
}
