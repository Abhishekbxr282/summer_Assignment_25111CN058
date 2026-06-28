#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct BankAccount *account) {
    printf("\nEnter Account Number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", account->name);
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &account->balance);
    printf("\nAccount created successfully!\n");
}

void depositMoney(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        account->balance += amount;
        printf("Deposit successful! New Balance: %.2f\n", account->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdrawMoney(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawal successful! New Balance: %.2f\n", account->balance);
    } else if (amount > 0) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

void checkBalance(struct BankAccount account) {
    printf("\n--- Account Details ---");
    printf("\nAccount Number: %d", account.accountNumber);
    printf("\nHolder Name: %s", account.name);
    printf("\nCurrent Balance: %.2f\n", account.balance);
}

int main() {
    struct BankAccount account;
    int choice = 0;
    int accountCreated = 0;

    while (choice != 5) {
        printf("\n=== Bank Management System ===");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                accountCreated = 1;
                break;
            case 2:
                if (accountCreated) {
                    depositMoney(&account);
                } else {
                    printf("\nPlease create an account first.\n");
                }
                break;
            case 3:
                if (accountCreated) {
                    withdrawMoney(&account);
                } else {
                    printf("\nPlease create an account first.\n");
                }
                break;
            case 4:
                if (accountCreated) {
                    checkBalance(account);
                } else {
                    printf("\nPlease create an account first.\n");
                }
                break;
            case 5:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
        }
    }
    return 0;
}
