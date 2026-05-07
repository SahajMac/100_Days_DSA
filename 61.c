#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize n x n adjacency matrix with 0s
    int adj[100][100] = {0};
    
    // Read m edges and populate matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;  // Convert to 0-based indexing
        
        adj[u][v] = 1;  // Directed edge u→v
        
        // For undirected graph, uncomment next line:
        // adj[v][u] = 1;
    }
    
    // Print adjacency matrix row by row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}