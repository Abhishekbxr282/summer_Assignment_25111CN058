#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }
    struct Book newBook;
    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.id);
    getchar();
    printf("Enter Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    newBook.available = 1;
    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-30s %-15s\n", "ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-30s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books to search.\n");
        return;
    }
    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book with ID %d not found.\n", searchId);
}

void deleteBook() {
    if (bookCount == 0) {
        printf("\nNo books to delete.\n");
        return;
    }
    int deleteId, found = 0;
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &deleteId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == deleteId) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", deleteId);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("\nExiting system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}
