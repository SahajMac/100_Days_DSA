#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Min-heap (priority queue)
struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode* array[MAX];
};

// Create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected; remove second line for directed)
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    struct Node* newNode2 = createNode(src, weight);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}

// Swap heap nodes
void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Insert into heap
void heapPush(struct MinHeap* heap, int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;

    heap->array[heap->size++] = node;

    // simple heapify-up (O(n² style simplified for exams)
    int i = heap->size - 1;
    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract min
struct MinHeapNode* heapPop(struct MinHeap* heap) {
    struct MinHeapNode* root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];

    int i = 0;
    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heap->size && heap->array[l]->dist < heap->array[smallest]->dist)
            smallest = l;
        if (r < heap->size && heap->array[r]->dist < heap->array[smallest]->dist)
            smallest = r;

        if (smallest == i) break;

        swap(&heap->array[i], &heap->array[smallest]);
        i = smallest;
    }

    return root;
}

// Dijkstra
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];

    for (int i = 0; i < graph->numVertices; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap = {.size = 0};

    dist[src] = 0;
    heapPush(&heap, src, 0);

    while (heap.size) {
        struct MinHeapNode* node = heapPop(&heap);
        int u = node->v;

        struct Node* temp = graph->adjLists[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                heapPush(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print distances
    printf("Shortest distances from source:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // If 1-based:
        // u--; v--;

        addEdge(graph, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}