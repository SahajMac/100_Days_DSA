#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize adjacency matrix with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[MAX] = {0};
    int key[MAX];

    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX;

    // Start from node 1
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {

        int min = INT_MAX, u = -1;

        // Pick minimum key vertex not yet included
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}