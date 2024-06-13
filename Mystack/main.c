#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList list;
	
	initStack(&list);
//	createStack(&list);
	stack_push(&list, 1);
	stack_push(&list, 2);
	stack_push(&list, 3);
	stack_push(&list, 4);
	
	stack_peek(list);
	
	display(list);
	
//	visualize(list);
	
	return 0;
}
