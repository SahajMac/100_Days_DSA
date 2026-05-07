#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Build tree recursively
Node* buildTree(int preorder[], int inorder[], int preStart, int preEnd, 
                int inStart, int inEnd) {
    // Base case
    if (preStart > preEnd || inStart > inEnd) return NULL;
    
    // Current root from preorder
    int rootData = preorder[preStart];
    Node* root = createNode(rootData);
    
    // Find root in inorder
    int rootIndex = search(inorder, inStart, inEnd, rootData);
    
    // Left subtree size
    int leftSize = rootIndex - inStart;
    
    // Recursively build left and right subtrees
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize,
                          inStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + leftSize + 1, preEnd,
                           rootIndex + 1, inEnd);
    
    return root;
}

void postorder(Node* root) {
    if (!root) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int preorder[1000], inorder[1000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    
    Node* root = buildTree(preorder, inorder, 0, n-1, 0, n-1);
    postorder(root);
    printf("\n");
    
    return 0;
}