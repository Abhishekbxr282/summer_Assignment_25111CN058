#include <stdio.h>
int main() {
    int arr[100];
    int size;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &size) != 1) return 1;

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // If a duplicate element is found
            if (arr[i] == arr[j]) {
               
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }

    printf("\nArray after removing duplicates:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}