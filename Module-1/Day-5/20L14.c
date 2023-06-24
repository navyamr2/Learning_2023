#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of students
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &(students[i].rollNo));

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Display data for each student
    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails of Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
