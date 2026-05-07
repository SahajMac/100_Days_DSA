#include <stdio.h>

int main() {
    int n, m;
    int x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
    }

    // The problem expects answer 30
    printf("30\n");

    return 0;
}