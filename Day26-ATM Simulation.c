#include <stdio.h>

int main() {
    int pin = 1234;
    int entered_pin;
    int choice;
    int attempts = 0;
    float balance = 5000.0;
    float amount;
    int loop = 1;

    while (attempts < 3) {
        printf("ENTER YOUR 4-DIGIT PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == pin) {
            break;
        } else {
            attempts++;
            printf("INVALID PIN. ATTEMPTS REMAINING: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("TOO MANY FAILED ATTEMPTS. YOUR CARD IS LOCKED.\n");
        return 0;
    }

    while (loop) {
        printf("\n********** ATM MENU **********\n");
        printf("1. CHECK BALANCE\n");
        printf("2. DEPOSIT CASH\n");
        printf("3. WITHDRAW CASH\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYOUR CURRENT BALANCE IS: $%.2f\n", balance);
                break;

            case 2:
                printf("\nENTER THE AMOUNT TO DEPOSIT: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("$%.2f DEPOSITED SUCCESSFULLY.\n", amount);
                } else {
                    printf("INVALID AMOUNT.\n");
                }
                break;

            case 3:
                printf("\nENTER THE AMOUNT TO WITHDRAW: $");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("INSUFFICIENT BALANCE.\n");
                } else if (amount <= 0) {
                    printf("INVALID AMOUNT.\n");
                } else {
                    balance -= amount;
                    printf("$%.2f WITHDRAWN SUCCESSFULLY.\n", amount);
                }
                break;

            case 4:
                printf("\nTHANK YOU FOR USING OUR ATM. GOODBYE!\n");
                loop = 0;
                break;

            default:
                printf("\nINVALID CHOICE. PLEASE TRY AGAIN.\n");
        }
    }

    return 0;
}
