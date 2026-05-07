#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;

    // Sum of primary diagonal
    for(int i = 0; i < m && i < n; i++) {
        sum += A[i][i];
    }

    // Output
    printf("%d", sum);

    return 0;
}