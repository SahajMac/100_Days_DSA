#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int best_sum = arr[left] + arr[right];
    int best_left = left, best_right = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        // If sum is closer to zero than current best
        if (abs(sum) < abs(best_sum)) {
            best_sum = sum;
            best_left = left;
            best_right = right;
        }

        if (sum == 0) {
            break;  // can't get closer
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    // Print the pair (smaller first, as in example)
    printf("%d %d\n", arr[best_left], arr[best_right]);

    return 0;
}