#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int isIssued;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== MINI LIBRARY SYSTEM MENU ===");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

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
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Mini Library System. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary capacity reached! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with this ID already exists!\n");
            return;
        }
    }

    printf("Enter Book Title: ");
    getchar();
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.isIssued = 0;

    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books found in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-30s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-30s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isIssued ? "Issued" : "Available");
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].isIssued ? "Issued" : "Available");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", searchId);
}

void issueBook() {
    int issueId;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issueId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == issueId) {
            if (library[i].isIssued == 1) {
                printf("\nSorry, this book is already issued to someone else.\n");
            } else {
                library[i].isIssued = 1;
                printf("\nBook '%s' issued successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("\nBook with ID %d does not exist.\n", issueId);
}

void returnBook() {
    int returnId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (library[i].isIssued == 0) {
                printf("\nThis book is already marked as available in the library.\n");
            } else {
                library[i].isIssued = 0;
                printf("\nBook '%s' returned successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("\nBook with ID %d does not belong to this library.\n", returnId);
}
