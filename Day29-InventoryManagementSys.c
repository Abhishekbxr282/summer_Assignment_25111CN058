#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nInventory full!\n");
        return;
    }
    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: ID already exists!\n");
            return;
        }
    }
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int searchId;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void updateStock() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int updateId, newQuantity;
    printf("\nEnter Item ID to update stock: ");
    scanf("%d", &updateId);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Current quantity: %d\nEnter new quantity: ", inventory[i].quantity);
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                printf("\nExiting system.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
