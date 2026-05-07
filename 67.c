#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Stack
struct Stack {
    int items[MAX];
    int top;
};

// Stack operations
void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    return s->items[s->top--];
}

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS for topo sort
void topoDFS(struct Graph* graph, int vertex, struct Stack* stack) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        if (!graph->visited[temp->vertex]) {
            topoDFS(graph, temp->vertex, stack);
        }
        temp = temp->next;
    }

    push(stack, vertex); // push after visiting children
}

// Topological sort
void topologicalSort(struct Graph* graph) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topoDFS(graph, i, &stack);
        }
    }

    while (stack.top != -1) {
        printf("%d ", pop(&stack));
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // If 1-based:
        // u--; v--;

        addEdge(graph, u, v);
    }

    printf("Topological Order: ");
    topologicalSort(graph);

    return 0;
}