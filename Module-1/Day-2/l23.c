#include <stdio.h>
#include <string.h>

void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sortNames(char *names[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(&names[j], &names[j + 1]);
            }
        }
    }
}

void printNames(char *names[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int size = sizeof(names) / sizeof(names[0]);

    printf("Names before sorting:\n");
    printNames(names, size);

    sortNames(names, size);

    printf("\nNames after sorting:\n");
    printNames(names, size);

    return 0;
}
