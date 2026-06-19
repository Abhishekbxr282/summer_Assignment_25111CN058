#include <stdio.h>
int main() {
    int matrix[10][10];
    int size, i, j;
    int principal_sum = 0;
    int secondary_sum = 0;

    printf("Enter the size of the square matrix (e.g., 3 for 3x3): ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe entered matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < size; i++) {
        principal_sum += matrix[i][i];
        secondary_sum += matrix[i][size - i - 1];
    }

    printf("\nSum of Principal Diagonal elements: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal elements: %d\n", secondary_sum);

    return 0;
}
