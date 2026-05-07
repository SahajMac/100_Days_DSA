#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key) {
            count++;
        }
        head = head->next;
    }

    return count;
}

int main() {
    int n, key;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    struct Node* head = createList(arr, n);

    int result = countOccurrences(head, key);
    printf("%d\n", result);

    return 0;
}