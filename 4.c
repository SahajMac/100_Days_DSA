#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Two-pointer approach: left from start, right from end
    int left = 0;
    int right = n - 1;
    
    while(left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
    
    // Print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}