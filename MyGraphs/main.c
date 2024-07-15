#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');
    
    addEdge('A', 'B');
    addEdge('A', 'D');
    addEdge('A', 'C');
    addEdge('B', 'D');
    addEdge('B', 'C');
    addEdge('C', 'D');
    addEdge('E', 'B');
    addEdge('E', 'D');
    
    printf("Initial Graph:\n");
    printAdjMatrix();
    printAdjList();
    
    deleteEdge('A', 'D');
    deleteVertex('E');
    
    printf("\nGraph after deleting vertex E and edge A-D:\n");
    printAdjMatrix();
    printAdjList();
    
	return 0;
}
