#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adj;
    int visited[MAX];
};

// Queue
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front >= rear) front = rear = -1;
    else front++;
    return val;
}

int isEmpty() {
    return front == -1;
}

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int n) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->n = n;
    g->adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));

    for (int i = 1; i <= n; i++) {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

// Add edge (undirected)
void addEdge(struct Graph* g, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    struct Node* newNode2 = createNode(u);
    newNode2->next = g->adj[v];
    g->adj[v] = newNode2;
}

// BFS traversal
int bfsCount(struct Graph* g, int start) {
    int count = 0;

    g->visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int node = dequeue();
        count++;

        struct Node* temp = g->adj[node];

        while (temp) {
            int adj = temp->vertex;

            if (!g->visited[adj]) {
                g->visited[adj] = 1;
                enqueue(adj);
            }
            temp = temp->next;
        }
    }

    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int visitedCount = bfsCount(g, 1);

    if (visitedCount == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}