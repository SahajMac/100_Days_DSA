#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    
    int len = strlen(str);
    
    // Print in reverse order (mirror)
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}