#include <stdio.h>
int main() {
    int number, rem, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number < 0) {
        number = -number;
    }

    while (number != 0) {
        rem = number % 10; 
        sum = sum + rem;   
        number = number / 10;    
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}





