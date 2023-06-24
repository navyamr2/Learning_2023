#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to swap the fields of two Student structures
void swapFields(struct Student* s1, struct Student* s2) {
    int tempRollNo = s1->rollNo;
    s1->rollNo = s2->rollNo;
    s2->rollNo = tempRollNo;

    char tempName[50];
    strcpy(tempName, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, tempName);

    float tempMarks = s1->marks;
    s1->marks = s2->marks;
    s2->marks = tempMarks;
}

int main() {
    struct Student student1 = { 1001, "John Doe", 85.5 };
    struct Student student2 = { 2002, "Jane Smith", 92.0 };

    printf("Before Swapping:\n");
    printf("Student 1 - Roll No: %d, Name: %s, Marks: %.2f\n", student1.rollNo, student1.name, student1.marks);
    printf("Student 2 - Roll No: %d, Name: %s, Marks: %.2f\n", student2.rollNo, student2.name, student2.marks);

    // Swap the fields of student1 and student2
    swapFields(&student1, &student2);

    printf("\nAfter Swapping:\n");
    printf("Student 1 - Roll No: %d, Name: %s, Marks: %.2f\n", student1.rollNo, student1.name, student1.marks);
    printf("Student 2 - Roll No: %d, Name: %s, Marks: %.2f\n", student2.rollNo, student2.name, student2.marks);

    return 0;
}
