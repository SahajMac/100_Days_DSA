#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Comparator: sort by start time
int cmp(const void *a, const void *b) {
    Meeting *m1 = (Meeting*)a;
    Meeting *m2 = (Meeting*)b;
    return m1->start - m2->start;
}

// Comparator for end times (min heap simulation sorting)
int cmpEnd(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    // array to store end times (heap simulation)
    int endTimes[n];
    int rooms = 0;

    for (int i = 0; i < n; i++) {

        int placed = 0;

        // try to find a room that is free
        for (int j = 0; j < rooms; j++) {
            if (endTimes[j] <= arr[i].start) {
                endTimes[j] = arr[i].end;
                placed = 1;
                break;
            }
        }

        // if no room free, allocate new room
        if (!placed) {
            endTimes[rooms++] = arr[i].end;
        }
    }

    printf("%d\n", rooms);

    return 0;
}