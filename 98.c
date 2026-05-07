#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Sort by start time
int cmp(const void *a, const void *b) {
    Interval *i1 = (Interval*)a;
    Interval *i2 = (Interval*)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    // Result array
    Interval res[n];
    int idx = 0;

    res[0] = arr[0];

    // Step 2: merge intervals
    for (int i = 1; i < n; i++) {

        if (arr[i].start <= res[idx].end) {
            // overlap → merge
            if (arr[i].end > res[idx].end)
                res[idx].end = arr[i].end;
        } else {
            // no overlap → new interval
            idx++;
            res[idx] = arr[i];
        }
    }

    // Step 3: print merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", res[i].start, res[i].end);
    }

    return 0;
}