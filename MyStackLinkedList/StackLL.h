#ifndef Stack_LinkedList
#define Stack_LinkedList

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} StackLinkedList;

void initStack(StackLinkedList *s);

StackLinkedList createStack();

bool isEmpty(StackLinkedList *s);

void stack_push(StackLinkedList *s, int elem);
bool stack_pop(StackLinkedList *s);

int stack_peek(StackLinkedList *s);

void display(StackLinkedList *s);
void visualize(StackLinkedList *s);

#endif
