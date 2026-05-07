#include <stdio.h>
#include <string.h>

#define MAX 256

int main() {
    char s[1000];
    scanf("%s", s);

    int firstIndex[MAX];

    // initialize all as not seen
    for (int i = 0; i < MAX; i++)
        firstIndex[i] = -1;

    int minSecondIndex = 100000;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = s[i];

        if (firstIndex[ch] == -1) {
            // first time seen
            firstIndex[ch] = i;
        } else {
            // repeated character
            if (i < minSecondIndex) {
                minSecondIndex = i;
                result = ch;
            }
        }
    }

    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}