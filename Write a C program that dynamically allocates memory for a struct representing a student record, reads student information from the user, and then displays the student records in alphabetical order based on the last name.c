//Write a C program that dynamically allocates memory for a struct representing a student record, reads student information from the user, and then displays the student records in alphabetical order based on the last name.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    char firstName[50];
    char lastName[50];
    int age;
    float grade;
};

// Function to compare two student records based on last name for sorting
int compareStudents(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    return strcmp(studentA->lastName, studentB->lastName);
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for an array of students
    struct Student* students = (struct Student*) malloc(numStudents * sizeof(struct Student));

    // Read student information from user
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the first name of student %d: ", i + 1);
        scanf("%s", students[i].firstName);
        printf("Enter the last name of student %d: ", i + 1);
        scanf("%s", students[i].lastName);
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &students[i].age);
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }

    // Sort student records based on last name using qsort() function
    qsort(students, numStudents, sizeof(struct Student), compareStudents);

    // Display student records in alphabetical order based on last name
    printf("\nStudent Records (Alphabetical Order):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
        printf("--------------------------\n");
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
