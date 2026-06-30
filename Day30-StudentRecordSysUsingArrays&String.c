#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};


void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        getchar(); 

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("System full! Cannot add more student records.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    getchar();

    printf("Enter Name: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);
    
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", 
               students[i].rollNumber, 
               students[i].name, 
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int targetRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}
