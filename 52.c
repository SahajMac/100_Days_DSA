#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n, int index) {
    if (index >= n || arr[index] == -1) return NULL;
    Node* root = createNode(arr[index]);
    root->left = buildTree(arr, n, 2 * index + 1);
    root->right = buildTree(arr, n, 2 * index + 2);
    return root;
}

Node* findLCA(Node* root, int p, int q) {
    if (!root || root->value == p || root->value == q) return root;
    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n, p, q;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &p, &q);
    Node* root = buildTree(arr, n, 0);
    Node* lca = findLCA(root, p, q);
    if (lca) printf("%d\n", lca->value);
    return 0;
}