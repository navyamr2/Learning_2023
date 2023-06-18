#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int countA[size], countB[size];
    int i, j;

    // Initialize count arrays to 0
    for (i = 0; i < size; i++) {
        countA[i] = 0;
        countB[i] = 0;
    }

    // Count occurrences of items in boxA
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                countA[i]++;
            }
        }
    }

    // Count occurrences of items in boxB
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (boxB[i] == boxA[j]) {
                countB[i]++;
            }
        }
    }

    // Check if there is a one-to-one mapping of items
    for (i = 0; i < size; i++) {
        if (countA[i] != 1 || countB[i] != 1) {
            return 0; // No one-to-one mapping found
        }
    }

    return 1; // One-to-one mapping found
}

int main() {
    int boxA[] = {200, 10, -90};
    int boxB[] = {-90, 200, 10};
    int size = sizeof(boxA) / sizeof(boxA[0]);

    int result = compareBoxes(boxA, boxB, size);

    if (result == 1) {
        printf("The boxes have a one-to-one mapping of items.\n");
    } else {
        printf("The boxes do not have a one-to-one mapping of items.\n");
    }

    return 0;
}

