#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n][n];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int isIdentity = 1;

    // Check identity matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            // Diagonal elements should be 1
            if(i == j && A[i][j] != 1) {
                isIdentity = 0;
                break;
            }

            // Non-diagonal elements should be 0
            if(i != j && A[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if(isIdentity == 0) {
            break;
        }
    }

    // Output result
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}