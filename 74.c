#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][MAX_LEN];
    int freq[MAX] = {0};
    int unique = 0;

    char temp[MAX_LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", temp);

        int found = 0;

        // check if already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // new candidate
        if (!found) {
            strcpy(names[unique], temp);
            freq[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char winner[MAX_LEN];

    for (int i = 0; i < unique; i++) {
        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if (freq[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}