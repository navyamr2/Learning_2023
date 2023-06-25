#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

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

    displayStructArray(students, arraySize);

    free(students); // Deallocate the dynamically allocated memory

    return 0;
}
