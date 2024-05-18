#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency list node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Stack structure for DFS
struct Stack {
    struct Node* top;
};

// Create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push an item to the stack
void push(struct Stack* stack, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    struct Node* temp = stack->top;
    int poppedVertex = temp->vertex;
    stack->top = temp->next;
    free(temp);
    return poppedVertex;
}

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    int i;
    for (i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as not visited (0)
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth First Search traversal using stack
void DFS(struct Graph* graph, int startVertex) {
    struct Stack* stack = createStack();
    
    // Push the start vertex onto the stack
    push(stack, startVertex);
    
    while (!isEmpty(stack)) {
        // Pop a vertex from the stack
        int currentVertex = pop(stack);

        // If the current vertex has not been visited, mark it visited and process it
        if (!graph->visited[currentVertex]) {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = 1;

            // Push all adjacent vertices onto the stack
            struct Node* temp = graph->adjLists[currentVertex];
            while (temp != NULL) {
                int adjVertex = temp->vertex;
                if (!graph->visited[adjVertex])
                    push(stack, adjVertex);
                temp = temp->next;
            }
        }
    }

    // Free the stack memory
    free(stack);
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    printf("Depth First Traversal using stack (linked list implementation) starting from vertex 0: ");
    DFS(graph, 0);
return 0;
}