#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    float marks;
};

void readStudentData(struct Student* student) {
    printf("Enter Name: ");
    scanf(" %[^\n]", student->name);

    printf("Enter Marks: ");
    scanf("%f", &(student->marks));
}

void writeStudentData(const struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);
}

float calculateAverageMarks(const struct Student* students, int n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }

    return sum / n;
}

void printStudentsAboveBelowAverage(const struct Student* students, int n, float averageMarks) {
    printf("\nStudents scoring above the average marks:\n");

    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }

    printf("\nStudents scoring below the average marks:\n");

    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int n;
    float averageMarks;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        readStudentData(&students[i]);
    }

    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails of Student %d:\n", i + 1);
        writeStudentData(&students[i]);
    }

    averageMarks = calculateAverageMarks(students, n);
    printf("\nAverage Marks: %.2f\n", averageMarks);

    printStudentsAboveBelowAverage(students, n, averageMarks);

    free(students);

    return 0;
}
