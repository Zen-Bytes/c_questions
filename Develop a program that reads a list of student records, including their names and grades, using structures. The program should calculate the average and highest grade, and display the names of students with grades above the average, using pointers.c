//Develop a program that reads a list of student records, including their names and grades, using structures. The program should calculate the average and highest grade, and display the names of students with grades above the average, using pointers.

#include <stdio.h>
#include <string.h>

// Structure to store student record
struct stud {
    char name[50];
    int grade;
};

int main() {
    int numstud;
    printf("Enter the number of students: ");
    scanf("%d", &numstud);

    struct stud* students = (struct stud*) malloc(numstud * sizeof(struct stud));

    // Reading student records from the user
    for (int i = 0; i < numstud; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }
    // average 
    int sum = 0;
    for (int i = 0; i < numstud; i++) {
        sum += students[i].grade;
    }
    double average = (double)sum / numstud;

    //highest_grade
    int highest = students[0].grade;
    for (int i = 1; i < numstud; i++) {
        if (students[i].grade > highest) {
            highest = students[i].grade;
        }
    }
    printf("\nAverage Grade: %.2lf\n", average);
    printf("Highest Grade: %d\n", highest);
    printf("Students with grades above average:\n");
    for (int i = 0; i < numstud; i++) {
        if (students[i].grade > average) {
            printf("%s\n", students[i].name);
        }
    }
    free(students);

    return 0;
}

