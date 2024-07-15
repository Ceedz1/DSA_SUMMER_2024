#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 26 // Assuming vertex labels are characters A-Z

// Structure for a node in adjacency list
struct AdjListNode {
    char dest;
    struct AdjListNode* next;
};

// Structure for adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure for graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;

    // Adjacency matrix representation
    int** adjMatrix;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(char dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    // Initialize adjacency matrix with zeros
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph->adjMatrix[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; ++j)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, char src, char dest) {
    // Convert characters to array indices (assuming 'A'-'Z')
    int indexSrc = src - 'A';
    int indexDest = dest - 'A';

    // Add an edge in the adjacency list
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[indexSrc].head;
    graph->array[indexSrc].head = newNode;

    // Since graph is undirected, add edge in the adjacency matrix
    graph->adjMatrix[indexSrc][indexDest] = 1;
    graph->adjMatrix[indexDest][indexSrc] = 1;
}

// Function to remove an edge from the graph
void removeEdge(struct Graph* graph, char src, char dest) {
    // Convert characters to array indices (assuming 'A'-'Z')
    int indexSrc = src - 'A';
    int indexDest = dest - 'A';

    // Remove edge in the adjacency list
    struct AdjListNode* curr = graph->array[indexSrc].head;
    struct AdjListNode* prev = NULL;

    while (curr != NULL && curr->dest != dest) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return; // Edge not found

    if (prev == NULL)
        graph->array[indexSrc].head = curr->next;
    else
        prev->next = curr->next;

    free(curr);

    // Remove edge in the adjacency matrix
    graph->adjMatrix[indexSrc][indexDest] = 0;
    graph->adjMatrix[indexDest][indexSrc] = 0;
}

// Function to remove a vertex from the graph
void removeVertex(struct Graph* graph, char v) {
    // Convert character to array index (assuming 'A'-'Z')
    int index = v - 'A';

    // Remove all edges connected to vertex v in the adjacency list
    struct AdjListNode* curr;
    struct AdjListNode* temp;

    for (int i = 0; i < graph->V; ++i) {
        curr = graph->array[i].head;
        struct AdjListNode* prev = NULL;
        while (curr != NULL) {
            if (curr->dest == v) {
                if (prev == NULL) {
                    graph->array[i].head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                temp = curr;
                curr = curr->next;
                free(temp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Free the head of the adjacency list for vertex v
    curr = graph->array[index].head;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    // Set head of the adjacency list to NULL for vertex v
    graph->array[index].head = NULL;

    // Remove corresponding row and column in the adjacency matrix
    for (int i = 0; i < graph->V; ++i) {
        graph->adjMatrix[index][i] = 0;
        graph->adjMatrix[i][index] = 0;
    }
}

// Function to print the adjacency list and adjacency matrix representations of the graph
void printGraph(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("Vertex %c: ", v + 'A');
        while (pCrawl) {
            printf(" %c", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }

    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < graph->V; ++i)
        printf(" %c", i + 'A');
    printf("\n");
    for (int i = 0; i < graph->V; ++i) {
        printf(" %c", i + 'A');
        for (int j = 0; j < graph->V; ++j) {
            printf(" %d", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a graph with 5 vertices (A, B, C, D, E)
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Add edges
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'D');
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'C');
    addEdge(graph, 'B', 'A');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'C', 'B');
    addEdge(graph, 'C', 'A');
    addEdge(graph, 'D', 'A');
    addEdge(graph, 'D', 'C');
    addEdge(graph, 'D', 'B'); 
    addEdge(graph, 'D', 'E');
    addEdge(graph, 'E', 'D');
    addEdge(graph, 'E', 'B');

    // Print the graph
    printf("Graph Representation:\n");
    printGraph(graph);

    // Remove a vertex and edges
    removeVertex(graph, 'C');
    removeVertex(graph, 'D');
    removeVertex(graph, 'E');

    // Print the updated graph
    printf("\nGraph after removing vertex 'C,D,E':\n");
    printGraph(graph);

    // Clean up
    // Free memory used by the graph
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            struct AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);

    // Free adjacency matrix
    for (int i = 0; i < graph->V; ++i)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);

    free(graph);

    return 0;
}

