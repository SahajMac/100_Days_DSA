#include <stdio.h>

#define EMPTY -1

int hashTable[1000];
int m;

// Simple hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == EMPTY) {
            hashTable[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == EMPTY)
            return 0; // stop early

        if (hashTable[idx] == key)
            return 1;
    }

    return 0;
}

int main() {
    int n, q;
    scanf("%d", &m);
    scanf("%d", &q);

    // initialize table
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        }
        else if (op[0] == 'S') {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}