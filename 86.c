#include <stdio.h>

int mySqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow: instead of mid*mid > n, you could compare mid > n/mid,
        // but for small n we just use long or check carefully.
        long long sq = (long long)mid * mid;

        if (sq == n) {
            return mid;
        } else if (sq < n) {
            ans = mid;      // mid is a valid candidate
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", mySqrt(n));
    return 0;
}