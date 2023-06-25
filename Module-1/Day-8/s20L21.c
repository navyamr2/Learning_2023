#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void addMember(struct Student** students, int* arraySize) {
    (*arraySize)++;
    struct Student* newStudents = (struct Student*)realloc(*students, (*arraySize) * sizeof(struct Student));

    if (newStudents != NULL) {
        *students = newStudents;

        // Prompt user to enter the details for the new member
        printf("Enter the details for the new member:\n");
        printf("Roll No.: ");
        scanf("%d", &((*students)[(*arraySize) - 1].rollno));

        printf("Name: ");
        scanf("%s", (*students)[(*arraySize) - 1].name);

        printf("Marks: ");
        scanf("%f", &((*students)[(*arraySize) - 1].marks));

        printf("New member added successfully!\n");
    } else {
        printf("Failed to add a new member. Memory allocation error!\n");
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

    addMember(&students, &arraySize);
    displayStructArray(students, arraySize);

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
