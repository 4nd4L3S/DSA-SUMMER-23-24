#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top=-1;
}

StackArrayList createStack(){
	StackArrayList s;
	
    s.top = -1; 
    
    return s;
}

bool isFull(StackArrayList s){
	if(s.top==MAX-1){
		return true;
	}else{
		return false;
	}
	
}

bool isEmpty(StackArrayList s){
	if(s.top==-1){
		return true;
	}else{
		return false;
	}
}

bool stack_push(StackArrayList *s, int elem){
	if(isFull(*s)){
		printf("STACK IS FULL");
		return false;
	}else {
		s->top++;
		s->data[s->top]= elem;
		return true;
	}
}

bool stack_pop(StackArrayList *s){
	if(isEmpty(*s)){
		printf("STACK IS EMPTY");
		return false;
	}else{
		s->top--;
		return true;
	}
	
}

int stack_peek(StackArrayList s){
	printf("PEEK: %d \n", s.data[s.top]);
	
	return s.data[s.top];
}

void display(StackArrayList s){
	StackArrayList temp;

    for(temp.top = -1; s.top != -1; s.top--){
        stack_push(&temp, s.data[s.top]);
    }

    while(temp.top != -1){
        printf("%d \n", temp.data[temp.top]);
        stack_pop(&temp);
    }
}

void visualize(StackArrayList s){
	StackArrayList temp;
	initStack(&temp);

    for(temp.top = -1; s.top != -1; s.top--){
        stack_push(&temp, s.data[s.top]);
    }
	
	printf("DATA - INDEX\n");
    while(temp.top != -1){
        printf("%d      ", temp.data[temp.top]);
        printf("%d \n", temp.top);
        stack_pop(&temp);
    }
}
