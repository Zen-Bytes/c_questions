//Write a C program that dynamically allocates memory for a struct representing a student record, reads student information from user, andn displays student records in alphabetical order based on last name.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure student 
struct stud {
    char firstName[50];
    char lastName[50];
    int age;
    float grade;
};
int compareStudents(const void* a, const void* b) {
    struct stud* studentA = (struct stud*)a;
    struct stud* studentB = (struct stud*)b;
    return strcmp(studentA->lastName, studentB->lastName);
}
int main() {
    int numstuds;
    printf("Enter number of students: ");
    scanf("%d", &numstuds);
    struct stud* students = (struct stud*) malloc(numstuds * sizeof(struct stud));
    for (int i = 0; i < numstuds; i++) {
        printf("Enter first name of student %d: ", i + 1);
        scanf("%s", students[i].firstName);
        printf("Enter last name of student %d: ", i + 1);
        scanf("%s", students[i].lastName);
        printf("Enter age of student %d: ", i + 1);
        scanf("%d", &students[i].age);
        printf("Enter grade of student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }
    qsort(students, numstuds, sizeof(struct stud), compareStudents);
    printf("\nStudent Records (Alphabetical Order):\n");
    for (int i = 0; i < numstuds; i++) {
        printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
        printf("--------------------------\n");
    }
    free(students);
    return 0;
}
