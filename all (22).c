#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end (used to build the list)
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Merge two sorted linked lists (returns head of merged list)
struct Node* mergeSortedLists(struct Node* h1, struct Node* h2) {
    struct Node* dummy = createNode(0);  // dummy node
    struct Node* curr = dummy;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data <= h2->data) {
            curr->next = h1;
            h1 = h1->next;
        } else {
            curr->next = h2;
            h2 = h2->next;
        }
        curr = curr->next;
    }

    // Attach remaining nodes
    if (h1 != NULL) {
        curr->next = h1;
    } else {
        curr->next = h2;
    }

    struct Node* mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

// Traverse and print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertAtEnd(&list1, x);
    }

    int m;
    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        insertAtEnd(&list2, x);
    }

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printList(mergedList);

    return 0;
}