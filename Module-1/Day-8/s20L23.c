#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapMembers(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
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
    int arraySize;
    printf("Enter the number of students: ");
    scanf("%d", &arraySize);

    struct Student* students = (struct Student*)malloc(arraySize * sizeof(struct Student));

    // Assume the array of structures is initialized with data here

    int index1, index2;
    printf("Enter the indexes of the members to swap (0 to %d): ", arraySize - 1);
    scanf("%d %d", &index1, &index2);

    if (index1 < 0 || index1 >= arraySize || index2 < 0 || index2 >= arraySize) {
        printf("Invalid indexes!\n");
    } else {
        swapMembers(students, index1, index2);
        printf("Members swapped successfully!\n");
        displayStructArray(students, arraySize);
    }

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
