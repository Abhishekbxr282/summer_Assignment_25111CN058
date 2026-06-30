#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

void displayMenu();
void addStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int *count);
void displayStudents(char names[][NAME_LENGTH], int rolls[], float gpas[], int count);
void searchStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int count);
void calculateAverage(float gpas[], int count);

int main() {
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    int studentRolls[MAX_STUDENTS];
    float studentGPAs[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    printf("=== Welcome to the Student Database System ===\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        getchar(); 

        switch (choice) {
            case 1:
                addStudent(studentNames, studentRolls, studentGPAs, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, studentRolls, studentGPAs, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentRolls, studentGPAs, studentCount);
                break;
            case 4:
                calculateAverage(studentGPAs, studentCount);
                break;
            case 5:
                printf("\nThank you for using the system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n---------------------------------------\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Name\n");
    printf("4. Calculate Class GPA Average\n");
    printf("5. Exit System\n");
    printf("---------------------------------------\n");
}

void addStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter student's full name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter roll number: ");
    scanf("%d", &rolls[*count]);

    printf("Enter GPA (0.0 - 4.0): ");
    scanf("%f", &gpas[*count]);

    (*count)++;
    printf("\nStudent record added successfully!\n");
}

void displayStudents(char names[][NAME_LENGTH], int rolls[], float gpas[], int count) {
    if (count == 0) {
        printf("\nNo student records found in the database.\n");
        return;
    }

    printf("\n================= STUDENT LIST =================\n");
    printf("%-5s %-30s %-10s\n", "Roll", "Name", "GPA");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-10.2f\n", rolls[i], names[i], gpas[i]);
    }
    printf("================================================\n");
}

void searchStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. Nothing to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    int found = 0;

    printf("\nEnter the name of the student to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(names[i], searchName) != NULL) {
            printf("Found -> Roll: %d | Name: %s | GPA: %.2f\n", rolls[i], names[i], gpas[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No student matched the name \"%s\".\n", searchName);
    }
}

void calculateAverage(float gpas[], int count) {
    if (count == 0) {
        printf("\nNo records available to calculate average.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += gpas[i];
    }

    float average = sum / count;
    printf("\nTotal Students: %d\n", count);
    printf("Class Average GPA: %.2f out of 4.00\n", average);
}
