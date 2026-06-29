#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void create(int arr[], int *size);
void display(int arr[], int size);
void insert(int arr[], int *size);
void delete_element(int arr[], int *size);
void search(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\n=== ARRAY OPERATING SYSTEM ===");
        printf("\n1. Create Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Search Element");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                create(arr, &size);
                break;
            case 2:
                display(arr, size);
                break;
            case 3:
                insert(arr, &size);
                break;
            case 4:
                delete_element(arr, &size);
                break;
            case 5:
                search(arr, size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

void create(int arr[], int *size) {
    int n;
    printf("Enter number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid size selection.\n");
        return;
    }
    *size = n;
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array initialized successfully.\n");
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Overflow error! Cannot insert element.\n");
        return;
    }
    int pos, val;
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &pos);
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void delete_element(int arr[], int *size) {
    if (*size == 0) {
        printf("Underflow error! Array is empty.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Deleted element: %d\n", arr[pos]);
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void search(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int target, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index: %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found in array.\n");
    }
}
