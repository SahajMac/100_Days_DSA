#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

// Check if boards can be painted with at most `maxTime` per painter
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0;  // single board exceeds maxTime

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];
        }
    }

    return (painters <= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[100000];
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxLen) maxLen = boards[i];
    }

    // Binary search on time
    long long low = maxLen, high = sum;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}