#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateArray(struct Student* students, int arraySize, int k) {
    k = k % arraySize; // Normalize k to handle cases where k is greater than arraySize

    // Allocate temporary memory to store the rotated elements
    struct Student* temp = (struct Student*)malloc(k * sizeof(struct Student));

    // Copy the last k elements to temp
    memcpy(temp, &students[arraySize - k], k * sizeof(struct Student));

    // Shift the remaining elements to the right by k positions
    memmove(&students[k], &students[0], (arraySize - k) * sizeof(struct Student));

    // Copy the rotated elements from temp to the beginning of the array
    memcpy(&students[0], temp, k * sizeof(struct Student));

    free(temp); // Deallocate the temporary memory
}

void displayStructArray(const struct Student* students, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No.: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int main() {
    int arraySize, k;
    printf("Enter the number of students: ");
    scanf("%d", &arraySize);

    struct Student* students = (struct Student*)malloc(arraySize * sizeof(struct Student));

    // Assume the array of structures is initialized with data here

    printf("Enter the value of K (number of positions to rotate): ");
    scanf("%d", &k);

    rotateArray(students, arraySize, k);
    displayStructArray(students, arraySize);

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
