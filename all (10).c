#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    int is_pal = 1;  // Assume yes
    
    while(left < right) {
        if(s[left] != s[right]) {
            is_pal = 0;
            break;
        }
        left++;
        right--;
    }
    
    if(is_pal) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}