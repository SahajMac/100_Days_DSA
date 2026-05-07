#include <stdio.h>

// Merge two sorted halves and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // All remaining elements in left half form inversions with arr[j]
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Modified merge sort that counts inversions
long long countInv(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += countInv(arr, temp, left, mid);
        invCount += countInv(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100000];
    int temp[100000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = countInv(arr, temp, 0, n - 1);

    printf("%lld\n", inversions);
    return 0;
}