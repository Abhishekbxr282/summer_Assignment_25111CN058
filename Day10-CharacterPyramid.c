#include <stdio.h>

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) {
       
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        for (int k = 0; k <= i; k++) {
            printf("%c ", 'A' + k);
        }

        printf("\n");
    }

    return 0;
}
