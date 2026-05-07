#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    int max = 0;

    // Input array and find max
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 1: frequency array
    int freq[max + 1];

    for (int i = 0; i <= max; i++)
        freq[i] = 0;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Step 2: prefix sum
    for (int i = 1; i <= max; i++)
        freq[i] += freq[i - 1];

    // Step 3: output array
    int output[n];

    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);

    return 0;
}