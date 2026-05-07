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

// Build tree recursively from inorder + postorder
Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, 
                int postStart, int postEnd) {
    // Base case
    if (inStart > inEnd || postStart > postEnd) return NULL;
    
    // Root is last element in postorder range
    int rootData = postorder[postEnd];
    Node* root = createNode(rootData);
    
    // Find root in inorder
    int rootIndex = search(inorder, inStart, inEnd, rootData);
    
    // Right subtree size
    int rightSize = inEnd - rootIndex;
    
    // Recursively build right and left subtrees
    root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd,
                           postEnd - rightSize, postEnd - 1);
    root->left = buildTree(inorder, postorder, inStart, rootIndex - 1,
                          postStart, postEnd - rightSize - 1);
    
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int inorder[1000], postorder[1000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
    
    Node* root = buildTree(inorder, postorder, 0, n-1, 0, n-1);
    preorder(root);
    printf("\n");
    
    return 0;
}