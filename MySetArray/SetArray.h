#ifndef Queue_Array
#define Queue_Array
#define MAX 15

typedef struct{
	int data[MAX];
	int count;
}SET;

void initSet(SET *x);
void displaySet(SET x);

void addElem(SET* x, int elem);

SET Union (SET A, SET B);
SET Intersection (SET A, SET B);

#endif
