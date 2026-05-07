#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position descending
int cmp(const void *a, const void *b) {
    Car *c1 = (Car*)a;
    Car *c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    // Step 1: sort by position (descending)
    qsort(cars, n, sizeof(Car), cmp);

    // store times
    double time[n];

    for (int i = 0; i < n; i++) {
        time[i] = (double)(target - cars[i].pos) / cars[i].speed;
    }

    int fleets = 0;
    double currTime = 0;

    // Step 2: traverse from front (closest to target)
    for (int i = 0; i < n; i++) {
        if (time[i] > currTime) {
            fleets++;
            currTime = time[i];
        }
    }

    printf("%d\n", fleets);

    return 0;
}