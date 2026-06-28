#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

typedef struct {
    int id;
    char name[50];
    int age;
    int is_booked;
} Ticket;

Ticket bookings[MAX_SEATS];

void initializeSystem() {
    for (int i = 0; i < MAX_SEATS; i++) {
        bookings[i].id = i + 1;
        bookings[i].is_booked = 0;
    }
}

void viewSeats() {
    printf("\n--- Seat Status ---\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (bookings[i].is_booked) {
            printf("[Seat %d: Booked] ", bookings[i].id);
        } else {
            printf("[Seat %d: Available] ", bookings[i].id);
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void bookTicket() {
    int seat_num;
    printf("\nEnter seat number (1-50): ");
    scanf("%d", &seat_num);

    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (bookings[seat_num - 1].is_booked) {
        printf("Seat %d is already booked!\n", seat_num);
    } else {
        printf("Enter passenger name: ");
        scanf(" %[^\n]s", bookings[seat_num - 1].name);
        printf("Enter passenger age: ");
        scanf("%d", &bookings[seat_num - 1].age);
        bookings[seat_num - 1].is_booked = 1;
        printf("Ticket booked successfully for Seat %d!\n", seat_num);
    }
}

void cancelTicket() {
    int seat_num;
    printf("\nEnter seat number to cancel (1-50): ");
    scanf("%d", &seat_num);

    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (bookings[seat_num - 1].is_booked == 0) {
        printf("Seat %d is already available. No cancellation needed.\n", seat_num);
    } else {
        bookings[seat_num - 1].is_booked = 0;
        strcpy(bookings[seat_num - 1].name, "");
        bookings[seat_num - 1].age = 0;
        printf("Ticket for Seat %d cancelled successfully.\n", seat_num);
    }
}

int main() {
    initializeSystem();
    int choice = 0;

    while (choice != 4) {
        printf("\n=== TICKET BOOKING SYSTEM ===\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewSeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("Exiting system. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
