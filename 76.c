#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int n, m;
int adj[MAXN][MAXN];   // adjacency matrix (or you can use adjacency list)
int visited[MAXN];

// DFS to mark all nodes in current component
void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // Read n (nodes) and m (edges)
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read m edges (1‑indexed)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);
    return 0;
}