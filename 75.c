#include <stdio.h>
#include <stdlib.h>

// A simple hash‑like structure using arrays (for small range of sums)
#define MAXN 1000
#define OFFSET 50000  // to handle negative sums

int main() {
    int arr[MAXN];
    int n = 0;

    // Read the array from a single line (space‑separated integers)
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int maxLen = 0;
    int prefixSum = 0;

    // store first occurrence index of each prefix sum
    int firstIndex[2 * OFFSET + 10];   // index by (prefixSum + OFFSET)
    int *seen = firstIndex + OFFSET;   // now seen[x] corresponds to prefixSum=x

    // mark all sums as "not seen"
    for (int i = -OFFSET; i <= OFFSET; i++) {
        seen[i] = -2;   // -2 = not seen
    }

    // treat sum 0 as seen at index -1
    seen[0] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            // subarray from start to i has sum 0
            maxLen = (i + 1) > maxLen ? (i + 1) : maxLen;
        } else if (seen[prefixSum] != -2) {
            // this sum occurred before
            int len = i - seen[prefixSum];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // first time this sum appears
            seen[prefixSum] = i;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}