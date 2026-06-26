#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 0) {
        printf("Invalid input! Age cannot be negative.\n");
    } 
   
    else if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } 
    
    else {
        printf("Sorry, you are not eligible to vote yet.\n");
        printf("You need to wait %d more year(s) to vote.\n", 18 - age);
    }

    return 0;
}
