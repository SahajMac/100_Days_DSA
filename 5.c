#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    
    int arr1[100];
    for(int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }
    
    int q;
    scanf("%d", &q);
    
    int arr2[100];
    for(int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Two-pointer merge for sorted arrays
    int i = 0, j = 0, k = 0;
    int merged[200];  // p+q <= 200 assumed
    
    while(i < p && j < q) {
        if(arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Add remaining from arr1
    while(i < p) {
        merged[k++] = arr1[i++];
    }
    
    // Add remaining from arr2
    while(j < q) {
        merged[k++] = arr2[j++];
    }
    
    // Print merged array
    for(int idx = 0; idx < k; idx++) {
        printf("%d ", merged[idx]);
    }
    printf("\n");
    
    return 0;
}