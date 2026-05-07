#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges (undirected not assumed, so directed here)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 1; count <= n - 1; count++) {

        int min = INT_MAX, u = -1;

        // pick minimum distance vertex
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        // relax neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}