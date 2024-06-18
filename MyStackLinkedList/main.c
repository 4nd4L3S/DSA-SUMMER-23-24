#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackLinkedList stack;
    
    initStack(&stack);
//    createStack();
	stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 4);

    display(&stack);

 	stack_peek(&stack);

    stack_pop(&stack);

    display(&stack);
//    visualize(&stack);

	return 0;
}
