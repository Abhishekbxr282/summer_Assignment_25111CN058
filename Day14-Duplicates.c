#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int i, j, k;
    int isAlreadyPrinted;
    int foundAny = 0;

    printf("Duplicate elements are: ");

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
           
            if (arr[i] == arr[j]) {
                
                isAlreadyPrinted = 0;
                for (k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        isAlreadyPrinted = 1;
                        break;
                    }
                }

                if (!isAlreadyPrinted) {
                    printf("%d ", arr[i]);
                    foundAny = 1;
                }
                break; 
            }
        }
    }

    if (!foundAny) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 7, 4, 8, 2, 4, 3, 9, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findDuplicates(arr, size);

    return 0;
}
