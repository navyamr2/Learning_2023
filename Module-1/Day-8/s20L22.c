#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void deleteMember(struct Student** students, int* arraySize) {
    if (*arraySize <= 0) {
        printf("No members to delete!\n");
        return;
    }

    (*arraySize)--;
    struct Student* newStudents = (struct Student*)malloc((*arraySize) * sizeof(struct Student));

    if (newStudents != NULL) {
        memcpy(newStudents, (*students) + 1, (*arraySize) * sizeof(struct Student));
        free(*students);
        *students = newStudents;

        printf("Member deleted successfully!\n");
    } else {
        printf("Failed to delete member. Memory allocation error!\n");
    }
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

    deleteMember(&students, &arraySize);
    displayStructArray(students, arraySize);

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
