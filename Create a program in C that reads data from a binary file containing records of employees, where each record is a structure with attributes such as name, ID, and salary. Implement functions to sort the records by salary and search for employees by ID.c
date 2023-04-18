//Create a program in C that reads data from a binary file containing records of employees, where each record is a structure with attributes such as name, ID, and salary. Implement functions to sort the records by salary and search for employees by ID.

#include <stdio.h>

#define MAX_EMPLOYEES 100

struct employee {
    char name[50];
    int id;
    float salary;
};

void read_employee(struct employee *e) {
    printf("Enter employee name: ");
    scanf("%s", e->name);

    printf("Enter employee ID: ");
    scanf("%d", &e->id);

    printf("Enter employee salary: ");
    scanf("%f", &e->salary);
}

void print_employee(struct employee e) {
    printf("Name: %s\n", e.name);
    printf("ID: %d\n", e.id);
    printf("Salary: %.2f\n", e.salary);
}

void sort_employees_by_salary(struct employee *employees, int num_employees) {
    int i, j;
    struct employee temp;

    for (i = 0; i < num_employees; i++) {
        for (j = i + 1; j < num_employees; j++) {
            if (employees[i].salary < employees[j].salary) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

struct employee *search_employee_by_id(struct employee *employees, int num_employees, int id) {
    int i;
    for (i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            return &employees[i];
        }
    }

    return NULL;
}

int main() {
    struct employee employees[MAX_EMPLOYEES];
    int num_employees = 0;

    while (num_employees < MAX_EMPLOYEES) {
        struct employee e;
        read_employee(&e);

        if (e.id == -1) {
            break;
        }

        employees[num_employees] = e;
        num_employees++;
    }

    sort_employees_by_salary(employees, num_employees);

    printf("Employees sorted by salary:\n");
    int i;
    for (i = 0; i < num_employees; i++) {
        print_employee(employees[i]);
    }

    printf("Enter employee ID to search: ");
    int id;
    scanf("%d", &id);

    struct employee *found_employee = search_employee_by_id(employees, num_employees, id);

    if (found_employee != NULL) {
        printf("Employee found:\n");
        print_employee(*found_employee);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}
