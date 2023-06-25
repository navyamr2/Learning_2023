#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStructArray(struct Student* students, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        students[i].rollno = 0;
        memset(students[i].name, 0, sizeof(students[i].name));
        students[i].marks = 0.0;
    }
}

int main() {
    int arraySize;
    printf("Enter the number of students: ");
    scanf("%d", &arraySize);

    struct Student* students = (struct Student*)malloc(arraySize * sizeof(struct Student));

    initializeStructArray(students, arraySize);

    // Printing the initialized array of structures
    for (int i = 0; i < arraySize; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No.: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
