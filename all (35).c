#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue
void enqueue(int val, int capacity) {
    rear = (rear + 1) % capacity;
    queue[rear] = val;
    size++;
}

// Dequeue + rotate
void rotate(int capacity) {
    int val = queue[front];                  // remove front
    front = (front + 1) % capacity;

    rear = (rear + 1) % capacity;            // add at rear
    queue[rear] = val;
}

// Display
void display(int capacity) {
    int i = front;
    for (int count = 0; count < size; count++) {
        printf("%d ", queue[i]);
        i = (i + 1) % capacity;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    int capacity = n;

    // Input & enqueue
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x, capacity);
    }

    scanf("%d", &m);

    // Perform m rotations
    for (int i = 0; i < m; i++) {
        rotate(capacity);
    }

    display(capacity);

    return 0;
}