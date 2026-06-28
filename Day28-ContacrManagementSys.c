#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        system("cls || clear"); 
        printf("\n=================================");
        printf("\n   CONTACT MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add New Contact");
        printf("\n2. View All Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Edit Contact");
        printf("\n5. Delete Contact");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("\nExiting program... Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please press Enter to try again.");
                getchar();
        }
    }
    return 0;
}

void addContact() {
    system("cls || clear");
    struct Contact c;
    FILE *file = fopen("contacts.dat", "ab"); 
    if (file == NULL) {
        printf("\nError opening file!\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    printf("--- Add New Contact ---\n");
    printf("Enter Name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0; 
    printf("Enter Phone Number: ");
    fgets(c.phone, 15, stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    fwrite(&c, sizeof(struct Contact), 1, file);
    fclose(file);

    printf("\nContact added successfully! Press Enter to continue...");
    getchar();
}

void viewContacts() {
    system("cls || clear");
    struct Contact c;
    FILE *file = fopen("contacts.dat", "rb");

    if (file == NULL) {
        printf("\nNo contacts found or error opening file!\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    printf("--- All Contacts ---\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("------------------------------------------------------------\n");

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        printf("%-20s %-15s %-30s\n", c.name, c.phone, c.email);
    }

    fclose(file);
    printf("\nPress Enter to continue...");
    getchar();
}

void searchContact() {
    system("cls || clear");
    char searchName[50];
    struct Contact c;
    FILE *file = fopen("contacts.dat", "rb");
    int found = 0;

    if (file == NULL) {
        printf("\nNo contacts found or error opening file!\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    printf("Enter name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    printf("\n--- Search Results ---\n");
    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (strcasecmp(c.name, searchName) == 0) { 
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", c.name, c.phone, c.email);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    fclose(file);
    printf("\nPress Enter to continue...");
    getchar();
}

void editContact() {
    system("cls || clear");
    char editName[50];
    struct Contact c;
    FILE *file = fopen("contacts.dat", "r+b"); 
    int found = 0;

    if (file == NULL) {
        printf("\nNo contacts found or error opening file!\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    printf("Enter the name of the contact you want to edit: ");
    fgets(editName, 50, stdin);
    editName[strcspn(editName, "\n")] = 0;

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (strcasecmp(c.name, editName) == 0) {
            found = 1;
            fseek(file, -sizeof(struct Contact), SEEK_CUR); 
            printf("\nEditing Contact: %s\n", c.name);
            printf("Enter New Name: ");
            fgets(c.name, 50, stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Enter New Phone Number: ");
            fgets(c.phone, 15, stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            printf("Enter New Email: ");
            fgets(c.email, 50, stdin);
            c.email[strcspn(c.email, "\n")] = 0;

            fwrite(&c, sizeof(struct Contact), 1, file);
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("\nContact updated successfully! Press Enter to continue...");
    } else {
        printf("\nContact not found. Press Enter to continue...");
    }
    getchar();
}

void deleteContact() {
    system("cls || clear");
    char deleteName[50];
    struct Contact c;
    FILE *file = fopen("contacts.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb"); 
    int found = 0;

    if (file == NULL || tempFile == NULL) {
        printf("\nError opening file!\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    printf("Enter the name of the contact to delete: ");
    fgets(deleteName, 50, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0;

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (strcasecmp(c.name, deleteName) == 0) {
            found = 1;
            continue; 
        }
        fwrite(&c, sizeof(struct Contact), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("contacts.dat");            
    rename("temp.dat", "contacts.dat"); 

    if (found) {
        printf("\nContact deleted successfully! Press Enter to continue...");
    } else {
        printf("\nContact not found. Press Enter to continue...");
    }
    getchar();
}
