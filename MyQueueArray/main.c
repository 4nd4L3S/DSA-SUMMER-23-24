#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "QueueArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue head;
	
	InitQ(&head);
	
	Display(head);
	
	Enqueue(&head, 1);
	Enqueue(&head, 2);
	Enqueue(&head, 3);
	Enqueue(&head, 4);
	Enqueue(&head, 5);
	Enqueue(&head, 6);
	Enqueue(&head, 7);
	Enqueue(&head, 8);

	
	Display(head);
	
	Dequeue(&head);
	
	Display(head);
	
	Dequeue(&head);
	
	Display(head);
	
	
	return 0;
}
