#include <stdio.h>
#include <stdlib.h>
#include "SetArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,elem;
	SET A,B,C,D;
	
	initSet(&A);
	initSet(&B);
	initSet(&C);
	initSet(&D);
	
	printf("Enter 5 Elements for SET A:\n");
	for(i=0;i<5;i++){
		scanf("%d",&elem);
		addElem(&A, elem);
	}
	printf("Set A: ");
    displaySet(A);
	
	printf("Enter 5 Elements for SET B:\n");
	for(i=0;i<5;i++){
		scanf("%d",&elem);
		addElem(&B, elem);
	}
	printf("Set B: ");
    displaySet(B);
    
    C = Union(A, B);
    printf("Union of A and B: ");
    displaySet(C);
    
    D = Intersection(A, B);
    printf("Intersection of A and B: ");
    displaySet(D);
	
	return 0;
}
