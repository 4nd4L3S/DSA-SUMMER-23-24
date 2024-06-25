#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void initQ(Queue *Q){
    Q->front = 1;
    Q->rear = 0;
}

void enQ(Queue *Q, Process data){

    if(Q->front == -1){
        Q->front = 0;
    }

    Q->array[++Q->rear] = data;
}

void table(Process solveVal[], int NProcess){
    int x;
    printf("\nTable: \n");
    printf("\nProcess\tBT\tAT\tCT\tWT\tTT\n");
    for(x = 0; x < NProcess; x++){
        printf("%c\t%d\t%d\t%d\t%d\t%d\n", solveVal[x].processID, solveVal[x].BT, solveVal[x].AT, solveVal[x].CT, solveVal[x].WT, solveVal[x].TaT);
    }
}

void calculate(Queue *Q, Process solveVal[], int NProcess){
    int CT[NProcess]; //completion time
    int ST[NProcess]; //starting time
    int WT[NProcess]; //waiting time
    int TaT[NProcess]; //Turn-around time
    int x, currTime = 0;


    for(x = 0; x < NProcess; x++){
        solveVal[x] = Q->array[Q->front + x];
    }

    for(x = 0; x < NProcess; x++){
        if(currTime < solveVal[x].AT){
            currTime = solveVal[x].AT;
        }

        ST[x] = currTime;
        CT[x] = currTime + solveVal[x].BT;
        WT[x] = ST[x] - solveVal[x].AT;
        TaT[x] = CT[x] - solveVal[x].AT;
        currTime = CT[x];
        
        solveVal[x].CT = CT[x];
        solveVal[x].WT = WT[x];
        solveVal[x].TaT = TaT[x];
    }

}
