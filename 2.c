#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100 for student problems
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos;
    scanf("%d", &pos);
    
    // Shift elements from pos to n-1 one position left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Print updated array (n-1 elements)
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}