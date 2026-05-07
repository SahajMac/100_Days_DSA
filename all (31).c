#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

// Pop
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Display (top to bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    // Push all elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack
    display();

    return 0;
}