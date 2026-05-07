#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

int *count;

// Merge function
void merge(Node arr[], Node temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

// Merge sort
void mergeSort(Node arr[], Node temp[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[n], temp[n];
    count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    mergeSort(arr, temp, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}