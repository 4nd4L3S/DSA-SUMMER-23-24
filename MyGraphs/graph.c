#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

// Function to find index of a vertex in the vertices array
int findVertexIndex(char vertex) {
	int i;
    for (i = 0; i < numVertices; ++i) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

// Function to add a new vertex to the graph
void addVertex(char vertex) {
    if (numVertices < MAX_VERTICES) {
        vertices[numVertices++] = vertex;
    } else {
        printf("Maximum number of vertices reached (%d). Cannot add vertex %c.\n", MAX_VERTICES, vertex);
    }
}

// Function to delete a vertex and its edges
void deleteVertex(char vertex) {
	int i,j;
    int vertexIndex = findVertexIndex(vertex);
    if (vertexIndex == -1) {
        printf("Vertex %c not found in graph. Cannot delete.\n", vertex);
        return;
    }
    
    // Remove vertex from vertices array
    for ( i = vertexIndex; i < numVertices - 1; ++i) {
        vertices[i] = vertices[i + 1];
    }
    numVertices--;
    
    // Remove edges involving this vertex in adjacency matrix
    // Shift rows up
    for ( i = vertexIndex; i < numVertices; ++i) {
        for ( j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
        }
    }
    
    // Shift columns left
    for ( j = vertexIndex; j < numVertices; ++j) {
        for ( i = 0; i < numVertices; ++i) {
            adjMatrix[i][j] = adjMatrix[i][j + 1];
        }
    }
}

// Function to add an edge between two vertices
void addEdge(char src, char dest) {
    int srcIndex = findVertexIndex(src);
    int destIndex = findVertexIndex(dest);
    
    if (srcIndex == -1) {
        printf("Vertex %c not found in graph. Adding vertex.\n", src);
        addVertex(src);
        srcIndex = numVertices - 1;
    }
    
    if (destIndex == -1) {
        printf("Vertex %c not found in graph. Adding vertex.\n", dest);
        addVertex(dest);
        destIndex = numVertices - 1;
    }
    
    // Add edge in adjacency matrix (undirected graph)
    adjMatrix[srcIndex][destIndex] = 1;
    adjMatrix[destIndex][srcIndex] = 1;
}

// Function to delete an edge between two vertices
void deleteEdge(char src, char dest) {
    int srcIndex = findVertexIndex(src);
    int destIndex = findVertexIndex(dest);
    
    if (srcIndex == -1 || destIndex == -1 || adjMatrix[srcIndex][destIndex] == 0) {
        printf("Edge %c-%c not found in graph. Cannot delete.\n", src, dest);
        return;
    }
    
    // Delete edge in adjacency matrix (undirected graph)
    adjMatrix[srcIndex][destIndex] = 0;
    adjMatrix[destIndex][srcIndex] = 0;
}

// Function to print the adjacency matrix
void printAdjMatrix() {
	int i,j;
    printf("\nAdjacency Matrix:\n");

    // Print column indices
    printf("    ");
    for ( i = 0; i < numVertices; ++i) {
        printf("%c ", vertices[i]);
    }
    printf("\n");

    // Print matrix row by row
    for (i = 0; i < numVertices; ++i) {
        printf("%c   ", vertices[i]);  // Print row index
        for ( j = 0; j < numVertices; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the adjacency list using the adjacency matrix
void printAdjList() {
	int i,j;
    printf("\nAdjacency List:\n");

    // Print each vertex and its adjacency list
    for ( i = 0; i < numVertices; ++i) {
        printf(" Adjacency list of vertex %c: ", vertices[i]);
        bool first = true;
        for ( j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] == 1) {
                if (!first) {
                    printf(", ");
                }
                printf("%c", vertices[j]);
                first = false;
            }
        }
        printf("\n");
    }
}

