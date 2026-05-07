#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Normalize k so that it's within [0, n-1]
    if (n > 0) {
        k = k % n;
    }

    // Print the rotated array (right rotation by k)
    for (int i = 0; i < n; i++) {
        int idx = (n - k + i) % n;
        printf("%d ", arr[idx]);
    }
    printf("\n");

    return 0;
}