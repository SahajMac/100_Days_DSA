#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left, *right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

int findLCA(struct Node* root, int n1, int n2) {
    if (n1 > n2) { int temp = n1; n1 = n2; n2 = temp; }
    while (root != NULL) {
        if (root->value >= n1 && root->value <= n2) return root->value;
        if (root->value < n1) root = root->right;
        else root = root->left;
    }
    return -1;
}

int main() {
    int N, n1, n2, val;
    struct Node* root = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &n1, &n2);
    printf("%d\n", findLCA(root, n1, n2));
    return 0;
}