#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // Ensure n does not exceed the limit to allow for the extra element
    if (n >= 100) return 1;
    
    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Shift elements from pos-1 to n-1 one position right
    // Check bounds to ensure we don't exceed the array size
    if (pos >= 1 && pos <= n + 1) {
        for(int i = n; i > pos - 1; i--) {
            arr[i] = arr[i - 1];
        }
        
        // Insert x at position pos-1
        arr[pos - 1] = x;
        
        // Print updated array (n+1 elements)
        for(int i = 0; i <= n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}