#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int A[r][c];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    while(top <= bottom && left <= right) {

        // Top row
        for(int i = left; i <= right; i++) {
            printf("%d ", A[top][i]);
        }
        top++;

        // Right column
        for(int i = top; i <= bottom; i++) {
            printf("%d ", A[i][right]);
        }
        right--;

        // Bottom row
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", A[bottom][i]);
            }
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", A[i][left]);
            }
            left++;
        }
    }

    return 0;
}