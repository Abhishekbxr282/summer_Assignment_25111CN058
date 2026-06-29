#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 100

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char str[], int maxLength) {
    fgets(str, maxLength, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    int choice;
    char str1[MAX_LIMIT], str2[MAX_LIMIT], str3[MAX_LIMIT * 2];
    int len, cmp;

    do {
        
        printf("\n====================================");
        printf("\n    STRING OPERATING SYSTEM MENU    ");
        printf("\n====================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        
        clearBuffer(); // Clear the remaining newline from scanf

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                readString(str1, MAX_LIMIT);
                len = strlen(str1);
                printf("Length of the string is: %d\n", len);
                break;

            case 2:
                printf("\nEnter the source string: ");
                readString(str1, MAX_LIMIT);
                strcpy(str2, str1);
                printf("Successfully Copied! New String: %s\n", str2);
                break;

            case 3:
                printf("\nEnter first string: ");
                readString(str1, MAX_LIMIT);
                printf("Enter second string: ");
                readString(str2, MAX_LIMIT);
                
                strcpy(str3, str1); 
                strcat(str3, str2);
                printf("Concatenated String: %s\n", str3);
                break;

            case 4:
                printf("\nEnter first string to compare: ");
                readString(str1, MAX_LIMIT);
                printf("Enter second string to compare: ");
                readString(str2, MAX_LIMIT);
                
                cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Both strings are identical.\n");
                } else if (cmp > 0) {
                    printf("First string is lexicographically greater than the second.\n");
                } else {
                    printf("Second string is lexicographically greater than the first.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                readString(str1, MAX_LIMIT);
                
                len = strlen(str1);
                printf("Reversed String: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting the String Operating System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
