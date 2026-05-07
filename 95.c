#include <stdio.h>
#include <stdlib.h>

// Insertion sort for a bucket (array of doubles)
void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    double *arr = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Step 1: create n buckets (each bucket is an array)
    int *bucketSize = (int *)calloc(n, sizeof(int));
    double **buckets = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        buckets[i] = (double *)malloc(n * sizeof(double));  // over‑allocate per bucket
    }

    // Step 2: distribute to buckets: bucket index = floor(n * x)
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]);
        if (bi == n) bi = n - 1;  // edge: 1.0 → clamp to last bucket
        buckets[bi][bucketSize[bi]++] = arr[i];
    }

    // Step 3: sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSize[i]);
    }

    // Step 4: concatenate all buckets into arr
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(bucketSize);
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(arr);

    return 0;
}