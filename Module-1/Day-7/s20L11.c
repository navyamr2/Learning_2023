#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringToStructArray(const char* inputString, struct Student* students, int arraySize) {
    char temp[20];
    const char* delimiter = " ";

    // Tokenize the input string
    char* token = strtok((char*)inputString, delimiter);
    for (int i = 0; i < arraySize; i++) {
        // Extract rollno
        students[i].rollno = atoi(token);

        // Extract name
        token = strtok(NULL, delimiter);
        strncpy(students[i].name, token, sizeof(students[i].name));

        // Extract marks
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        // Move to the next token
        token = strtok(NULL, delimiter);
    }
}

int main() {
    int arraySize;
    printf("Enter the number of students: ");
    scanf("%d", &arraySize);

    // Clear the input buffer
    while (getchar() != '\n');

    char inputString[100];
    printf("Enter the input string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline character

    struct Student* students = (struct Student*)malloc(arraySize * sizeof(struct Student));

    parseStringToStructArray(inputString, students, arraySize);

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
