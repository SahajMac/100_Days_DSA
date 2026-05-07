#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QNode {
    Node* node;
    int hd;
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
    queue[rear++] = (QNode){root, 0, 0};
    
    int i = 1;
    while (front < rear && i < n) {
        QNode curr = queue[front++];
        
        // Left child
        if (i < n && arr[i] != -1) {
            curr.node->left = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->left, curr.hd - 1, curr.level + 1};
        }
        i++;
        
        // Right child
        if (i < n && arr[i] != -1) {
            curr.node->right = createNode(arr[i]);
            queue[rear++] = (QNode){curr.node->right, curr.hd + 1, curr.level + 1};
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;
    
    // Find min/max hd first
    int min_hd = 0, max_hd = 0;
    
    // BFS to find hd range
    QNode temp_queue[1000];
    int front = 0, rear = 0;
    temp_queue[rear++] = (QNode){root, 0, 0};
    
    while (front < rear) {
        QNode curr = temp_queue[front++];
        if (curr.hd < min_hd) min_hd = curr.hd;
        if (curr.hd > max_hd) max_hd = curr.hd;
        
        if (curr.node->left)
            temp_queue[rear++] = (QNode){curr.node->left, curr.hd - 1, curr.level + 1};
        if (curr.node->right)
            temp_queue[rear++] = (QNode){curr.node->right, curr.hd + 1, curr.level + 1};
    }
    
    // Map: offset_hd -> nodes at each level
    int width = max_hd - min_hd + 1;
    int** map = (int**)malloc(width * sizeof(int*));
    int* counts = (int*)calloc(width, sizeof(int));
    
    for (int i = 0; i < width; i++) {
        map[i] = (int*)malloc(100 * sizeof(int));
    }
    
    // BFS to populate map
    front = 0; rear = 0;
    temp_queue[rear++] = (QNode){root, 0, 0};
    
    while (front < rear) {
        QNode curr = temp_queue[front++];
        int offset = curr.hd - min_hd;
        map[offset][counts[offset]++] = curr.node->data;
        
        if (curr.node->left)
            temp_queue[rear++] = (QNode){curr.node->left, curr.hd - 1, curr.level + 1};
        if (curr.node->right)
            temp_queue[rear++] = (QNode){curr.node->right, curr.hd + 1, curr.level + 1};
    }
    
    // Print column by column
    for (int col = 0; col < width; col++) {
        int first = 1;
        for (int i = 0; i < counts[col]; i++) {
            if (!first) printf(" ");
            printf("%d", map[col][i]);
            first = 0;
        }
        if (counts[col] > 0) printf("\n");
    }
    
    // Cleanup
    for (int i = 0; i < width; i++) {
        free(map[i]);
    }
    free(map);
    free(counts);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    verticalOrder(root);
    
    return 0;
}