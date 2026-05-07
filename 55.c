#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* node;
} QNode;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    Node* root = createNode(arr[0]);
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

void rightView(Node* root) {
    if (!root) return;
    
    QNode queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (QNode){root};
    
    int first = 1;
    
    while (front < rear) {
        int levelSize = rear - front;
        
        // Process all nodes at current level
        // Last node (rightmost) will be printed
        for (int i = 0; i < levelSize; i++) {
            QNode curr = queue[front++];
            
            // Print only the last node of each level
            if (i == levelSize - 1) {
                if (!first) printf(" ");
                printf("%d", curr.node->data);
                first = 0;
            }
            
            // Enqueue children (left first, then right)
            if (curr.node->left) {
                queue[rear++] = (QNode){curr.node->left};
            }
            if (curr.node->right) {
                queue[rear++] = (QNode){curr.node->right};
            }
        }
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
    rightView(root);
    printf("\n");
    return 0;
}