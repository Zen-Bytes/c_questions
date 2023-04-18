//Develop a program that reads a list of student records, including their names and grades, using structures. The program should calculate the average and highest grade, and display the names of students with grades above the average, using pointers.

#include <stdio.h>
#include <string.h>

// Structure to store student record
struct Student {
    char name[50];
    int grade;
};

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for an array of students
    struct Student* students = (struct Student*) malloc(numStudents * sizeof(struct Student));

    // Read student records from user
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }

    // Calculate average grade
    int sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].grade;
    }
    double average = (double)sum / numStudents;

    // Find highest grade
    int highest = students[0].grade;
    for (int i = 1; i < numStudents; i++) {
        if (students[i].grade > highest) {
            highest = students[i].grade;
        }
    }

    printf("\nAverage Grade: %.2lf\n", average);
    printf("Highest Grade: %d\n", highest);
    printf("Students with grades above average:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].grade > average) {
            printf("%s\n", students[i].name);
        }
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
