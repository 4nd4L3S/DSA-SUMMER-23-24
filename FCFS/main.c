#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
    Process processData;
    int x, n;

    initQ(&Q);

    printf("\nEnter no. of Processes: ");
    scanf("%d", &n);
    for(x = 0; x < n; x++){
        processData.processID = 'A' + x;  // Process ID generated from 'A' onwards
        printf("\nEnter Arrival Time for Process [%c]: ", processData.processID);
        scanf("%d", &processData.AT);
        printf("Enter Burst Time for Process [%c]: ", processData.processID);
        scanf("%d", &processData.BT);

        enQ(&Q, processData);
        fflush(stdin);
    }
    Process solveVal[n];

    calculate(&Q, solveVal, n);
    table(solveVal, n);

	return 0;
}
