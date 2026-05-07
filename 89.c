#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

// Check if we can allocate books so that each student gets at most `maxPages`
int canAllocate(int pages[], int n, int m, int maxPages) {
    int studentCount = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) return 0;  // single book exceeds limit

        if (sum + pages[i] <= maxPages) {
            sum += pages[i];
        } else {
            studentCount++;
            sum = pages[i];
        }
    }

    return (studentCount <= m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[100000];
    int sum = 0;
    int maxPage = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        sum += pages[i];
        if (pages[i] > maxPage) maxPage = pages[i];
    }

    // Binary search on the answer (max pages per student)
    int low = maxPage, high = sum;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try to minimize max pages
        } else {
            low = mid + 1;   // need larger max pages
        }
    }

    printf("%d\n", ans);
    return 0;
}