#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void modifyStudent(struct Student* student) {
    // Modify the members of the structure
    student->rollno = 1001;
    strcpy(student->name, "Aron");
    student->marks = 100.00;
}

struct Student* getModifiedStudent(struct Student* student) {
    // Create a new Student structure
    struct Student* modifiedStudent = malloc(sizeof(struct Student));

    // Copy the contents of the original structure to the modified structure
    memcpy(modifiedStudent, student, sizeof(struct Student));

    // Modify the members of the modified structure
    modifiedStudent->rollno = 1001;
    strcpy(modifiedStudent->name, "Aron");
    modifiedStudent->marks = 100.00;

    // Return the modified structure
    return modifiedStudent;
}

int main() {
    // Create a structure object
    struct Student student;

    // Pass the pointer to the structure to the modifyStudent function
    modifyStudent(&student);

    // Print the modified structure
    printf("Modified Student:\n");
    printf("Roll No: %d\n", student.rollno);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);

    // Pass the pointer to the structure to the getModifiedStudent function
    struct Student* modifiedStudent = getModifiedStudent(&student);

    // Print the modified structure
    printf("\nModified Student (Returned Pointer):\n");
    printf("Roll No: %d\n", modifiedStudent->rollno);
    printf("Name: %s\n", modifiedStudent->name);
    printf("Marks: %.2f\n", modifiedStudent->marks);

    // Free the dynamically allocated memory for the modified structure
    free(modifiedStudent);

    return 0;
}
