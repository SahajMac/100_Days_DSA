#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if(n == 0) {
        printf("\n");
        return 0;
    }
    
    // In-place removal using two pointers
    int write_idx = 1;  // Next position to write unique element
    
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            arr[write_idx] = arr[i];
            write_idx++;
        }
    }
    
    // Print first write_idx unique elements
    for(int i = 0; i < write_idx; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}