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
};

// Queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Queue functions
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;

    if (q->front == -1)
        q->front = 0;

    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];

    if (q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return item;
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

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    int inDegree[MAX] = {0};

    // Calculate in-degree
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    struct Queue q;
    initQueue(&q);

    // Add vertices with in-degree 0
    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegree[i] == 0)
            enqueue(&q, i);
    }

    int count = 0;

    // Process queue
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);
        count++;

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            inDegree[temp->vertex]--;

            if (inDegree[temp->vertex] == 0)
                enqueue(&q, temp->vertex);

            temp = temp->next;
        }
    }

    // Check for cycle
    if (count != graph->numVertices) {
        printf("\nCycle detected! Topological sort not possible.\n");
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