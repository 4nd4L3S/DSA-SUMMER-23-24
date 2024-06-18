#ifndef Queue_Array
#define Queue_Array
#define MAX 8

typedef struct{
	int elem[MAX];
	int front;
	int rear;
}Queue;

void InitQ(Queue *head);

bool isEmpty(Queue head);
bool isFull(Queue head);

void Enqueue(Queue *head, int x);
void Dequeue(Queue *head);

void Display(Queue head);

#endif
