#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  
    }
    
    int k;
    scanf("%d", &k);
    
    int comparisons = 0;
    int found = 0;
    int index = -1;
    
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if(found) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}