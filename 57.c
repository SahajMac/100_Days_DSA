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

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    Node* root = createNode(arr[0]);
    typedef struct {
        Node* node;
    } QNode;
    
    QNode queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (QNode){root};
    
    int i = 1;
    while (front < rear && i < n) {
        QNode curr = queue[front++];
        
        if (i < n && arr[i] != -1) {
            curr.node->left = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->left};
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            curr.node->right = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->right};
        }
        i++;
    }
    return root;
}

void mirrorTree(Node* root) {
    if (!root) return;
    
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    mirrorTree(root);
    inorder(root);
    printf("\n");
    
    return 0;
}