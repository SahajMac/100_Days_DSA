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

// Check if two trees are mirror images
int isMirror(Node* left, Node* right) {
    // Both null = symmetric
    if (left == NULL && right == NULL) 
        return 1;
    
    // One null, one not = not symmetric
    if (left == NULL || right == NULL) 
        return 0;
    
    // Values differ = not symmetric
    if (left->data != right->data) 
        return 0;
    
    // Check mirror property recursively:
    // left->left with right->right
    // left->right with right->left
    return isMirror(left->left, right->right) && 
           isMirror(left->right, right->left);
}

void checkSymmetric(Node* root) {
    if (isMirror(root->left, root->right)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    if (root) {
        checkSymmetric(root);
    } else {
        printf("YES\n");  // Empty tree is symmetric
    }
    
    return 0;
}