#include<stdio.h>
#include<stdlib.h>
#include "SetArray.h"

void initSet(SET *x){
	x->count=0;
}

void displaySet(SET x) {
	int i;
	
	printf("{ ");
	for (i = 0; i < x.count; i++) {
		printf("%d ", x.data[i]);
	}
	printf("}\n");
}

void addElem(SET* x, int elem) {
	int i, j;
	 if (x->count < MAX) {
        j = 0;
        while (j < x->count && x->data[j] < elem) {
            j++;
        }
        for (i = x->count; i > j; i--) {
            x->data[i] = x->data[i - 1];
        }
        x->data[j] = elem;
        x->count++;
    } else {
        printf("Set is full. Cannot add more elements.\n");
    }
}

SET Union (SET A, SET B) {
	int ctrA, ctrB;
	SET C;       
	C.count = 0;
	
	for (ctrA = ctrB = 0; ctrA < A.count && ctrB < B.count;) {
		if (A.data[ctrA] != B.data[ctrB]) { 
			if (A.data[ctrA] < B.data[ctrB]) {
    			C.data[C.count] = A.data[ctrA];
   				ctrA++;
			} else {
    			C.data[C.count] = B.data[ctrB];
    			ctrB++;
			}
			C.count++;
		}else {
			C.data[C.count++] = A.data[ctrA++];
			ctrB++;
		}
	}
	
	for (; ctrA < A.count; ctrA++) {
			C.data[C.count++] = A.data[ctrA];
	}
		
	for (; ctrB < B.count; ctrB++) {
			C.data[C.count++] = B.data[ctrB];
	}	
	
	return C;
}

SET Intersection (SET A, SET B) {
	int ctrA, ctrB;
	SET C;
	C.count = 0;
	
	for (ctrA = ctrB = 0; ctrA < A.count && ctrB < B.count;) {
		if (A.data[ctrA] == B.data[ctrB]) {
			C.data[C.count++] = A.data[ctrA++];
			ctrB++;
 		} else {
 			if (A.data[ctrA] < B.data[ctrB]) {
    			ctrA++;
			} else {
   			 ctrB++;
			}
		 }
	}
	
	return C;
}
