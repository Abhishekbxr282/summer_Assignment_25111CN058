#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nSystem full. Cannot add more employees.\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Designation: ");
    scanf(" %[^\n]s", emp.designation);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully.\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------\n");
    printf("%-5s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-5d %-20s %-20s %-10.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
    printf("--------------------------------------------------------------\n");
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n", 
                   employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nCurrent Details:\nName: %s | Designation: %s | Salary: %.2f\n", 
                   employees[i].name, employees[i].designation, employees[i].salary);
            
            printf("\nEnter New Name: ");
            scanf(" %[^\n]s", employees[i].name);
            printf("Enter New Designation: ");
            scanf(" %[^\n]s", employees[i].designation);
            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);
            
            printf("Employee records updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\n*** Employee Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
