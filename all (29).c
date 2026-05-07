#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create polynomial linked list
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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

// Print polynomial
void printPoly(struct Node* head) {
    while (head != NULL) {
        if (head->exp == 0) {
            printf("%d", head->coeff);
        } else if (head->exp == 1) {
            printf("%dx", head->coeff);
        } else {
            printf("%dx^%d", head->coeff, head->exp);
        }

        if (head->next != NULL) {
            printf(" + ");
        }

        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}