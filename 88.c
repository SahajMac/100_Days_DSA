#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place k cows with at least 'dist' distance apart
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int cnt = 1;          // place first cow at stalls[0]
    int prev = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - prev >= dist) {
            cnt++;
            prev = stalls[i];
        }
    }

    return (cnt >= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: sort the stalls
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: binary search on distance
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;      // this distance is possible, try larger
            low = mid + 1;
        } else {
            high = mid - 1; // this distance is not possible, try smaller
        }
    }

    printf("%d\n", ans);
    return 0;
}