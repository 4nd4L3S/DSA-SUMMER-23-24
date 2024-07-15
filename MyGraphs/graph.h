#ifndef graph
#define graph

#define MAX_VERTICES 10

// Global variables to store graph data


// Function to find index of a vertex in the vertices array
int findVertexIndex(char vertex);

// Function to add a new vertex to the graph
void addVertex(char vertex);

// Function to delete a vertex and its edges
void deleteVertex(char vertex);

// Function to add an edge between two vertices
void addEdge(char src, char dest);

// Function to delete an edge between two vertices
void deleteEdge(char src, char dest);
// Function to print the adjacency matrix
void printAdjMatrix();

// Function to print the adjacency list using the adjacency matrix
void printAdjList();
#endif
