#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* node;
    int level;
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
    queue[rear++] = (QNode){root, 0};
    
    int i = 1;
    while (front < rear && i < n) {
        QNode curr = queue[front++];
        
        if (i < n && arr[i] != -1) {
            curr.node->left = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->left, curr.level + 1};
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            curr.node->right = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->right, curr.level + 1};
        }
        i++;
    }
    return root;
}

void zigzagLevelOrder(Node* root) {
    if (!root) return;
    
    QNode queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (QNode){root, 0};
    
    int first = 1;
    
    while (front < rear) {
        int levelSize = rear - front;
        int level = queue[front].level;
        
        // Create temp array for current level
        int levelData[1000];
        int levelCount = 0;
        
        // Process current level (always left-to-right enqueue order)
        for (int i = 0; i < levelSize; i++) {
            QNode curr = queue[front++];
            levelData[levelCount++] = curr.node->data;
            
            // Enqueue children (left first, then right)
            if (curr.node->left) {
                queue[rear++] = (QNode){curr.node->left, level + 1};
            }
            if (curr.node->right) {
                queue[rear++] = (QNode){curr.node->right, level + 1};
            }
        }
        
        // Print in zigzag order
        if (level % 2 == 1) {
            // Odd level: reverse order (right to left)
            for (int i = levelCount - 1; i >= 0; i--) {
                if (!first) printf(" ");
                printf("%d", levelData[i]);
                first = 0;
            }
        } else {
            // Even level: normal order (left to right)
            for (int i = 0; i < levelCount; i++) {
                if (!first) printf(" ");
                printf("%d", levelData[i]);
                first = 0;
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
    zigzagLevelOrder(root);
    printf("\n");
    return 0;
}