#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 20

typedef struct{
    char processID;
    int AT;
    int BT;
    int CT;
    int WT;
    int TaT;
}Process;

typedef struct{
    Process array[MAX];
    int front;
    int rear;
}Queue;

void initQ(Queue *Q);

void enQ(Queue *Q, Process data);
void table(Process solveVal[], int NProcess);

void calculate(Queue *Q, Process solveVal[], int NProcess);


#endif
