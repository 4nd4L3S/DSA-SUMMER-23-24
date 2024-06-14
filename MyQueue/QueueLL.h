#ifndef Queue_LinkedList
#define Queue_LinkedList

typedef struct node{
	int elem;
	struct node *link;
}Node,*Nodeptr;

typedef struct{
	Nodeptr front;
	Nodeptr rear;
}Queue;

void InitQ(Queue *head);

bool isEmpty(Queue head);
void Enqueue(Queue *head, int x);

void Dequeue(Queue *head);

void Display(Queue head);

#endif
