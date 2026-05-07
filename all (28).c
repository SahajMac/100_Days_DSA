#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int n = getLength(head);
    k = k % n;
    if (k == 0) return head;

    // Find last node
    struct Node* temp = head;
    while (temp->next) temp = temp->next;

    // Make circular
    temp->next = head;

    // Move to new tail (n-k steps)
    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head
    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    scanf("%d", &k);

    struct Node* head = createList(arr, n);
    head = rotateRight(head, k);

    printList(head);

    return 0;
}