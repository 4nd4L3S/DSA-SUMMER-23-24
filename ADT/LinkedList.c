#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node{
	info data;
	struct node *next;
}node, *nodeptr;

void insertlast(nodeptr *head){
	nodeptr temp;
	
    while (*head != NULL) {
       	head = &((*head)->next);
    }
	temp=(nodeptr)malloc(sizeof(node));
	
	if(temp!=NULL){
		printf("Enter Name:");
		scanf("%s", temp->data.name);
		printf("Enter Id:");
		scanf("%d", &temp->data.idNum);
		printf("Enter Age:");
		scanf("%d", &temp->data.age);
		temp->next = NULL;
    	*head = temp; 	
	}
    
}

void deletelast(nodeptr *head){
	nodeptr *current = head;

    // Traverse the list until the last node
    while (*current != NULL && (*current)->next != NULL && (*current)->next->next != NULL) {
        current = &((*current)->next);
    }

    // Free the last node and update the next pointer of the second-to-last node
    nodeptr temp = *current;
    *current = (*current)->next;
    free(temp);
    if (*current == NULL) {
        *head = NULL; // Update head if the last node is deleted
    }
}

void insertfirst(nodeptr *head){
	nodeptr temp;
	temp=(nodeptr)malloc(sizeof(node));
	
	if (temp == NULL) {
        return;
    }
    printf("Enter Name:");
	scanf("%s", temp->data.name);
	printf("Enter Id:");
	scanf("%d", &temp->data.idNum);
	printf("Enter Age:");
	scanf("%d", &temp->data.age);
	temp->next = *head;
	
	*head= temp;
}

void deletefirst(nodeptr *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    nodeptr temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(nodeptr head){
	while(head!=NULL){
		printf("NAME:%s  ", head->data.name);
		printf("ID:%d  ", head->data.idNum);
		printf("AGE:%d  \n", head->data.age);
		head=head->next;
	}
	
	getch();
	
}

int main(){
	nodeptr head=NULL;
	int choice;
	
	while(choice<4){
		printf("COMMAND\n");
		printf(" 0-display\n 1-insertfirst\n 2-insertlast\n 3-deletefirst\n 4-deletelast\n");
		scanf("%d", &choice);
		system("cls");
				
		switch(choice){
			
			
			case 0:
				display(head);
				break;
			case 1:
				insertfirst(&head);
				break;
			case 2:
				insertlast(&head);
				break;
			case 3:
				deletefirst(&head);
				break;
			case 4:
				deletelast(&head);
				break;	
		}
	};
	
	
}
