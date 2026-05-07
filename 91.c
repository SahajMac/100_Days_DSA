#include <stdio.h>

// Merge two sorted halves: arr[low .. mid] and arr[mid+1 .. high]
void merge(int arr[], int temp[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    // Copy both halves into temp
    for (int x = low; x <= high; x++) {
        temp[x] = arr[x];
    }

    // Merge back into arr in sorted order
    while (i <= mid && j <= high) {
        if (temp[i] <= temp[j]) {
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        arr[k++] = temp[i++];
    }
    // Copy remaining elements from right half
    while (j <= high) {
        arr[k++] = temp[j++];
    }
}

// Merge sort: divide, sort halves, merge
void mergeSort(int arr[], int temp[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, temp, low, mid);
        mergeSort(arr, temp, mid + 1, high);
        merge(arr, temp, low, mid, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    int temp[1000];   // temporary array for merging

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, temp, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}