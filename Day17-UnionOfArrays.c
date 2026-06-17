#include <stdio.h>
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0; 

int findUnion(int arr1[], int size1, int arr2[], int size2, int unionArr[]) {
    int k = 0;

    for (int i = 0; i < size1; i++) {
        if (!isDuplicate(unionArr, k, arr1[i])) {
            unionArr[k++] = arr1[i];
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!isDuplicate(unionArr, k, arr2[i])) {
            unionArr[k++] = arr2[i];
        }
    }

    return k; 
}

int main() {
    int arr1[] = {1, 3, 2, 3, 5};
    int arr2[] = {2, 4, 5, 6, 2};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int unionArr[size1 + size2]; 
    
    int unionSize = findUnion(arr1, size1, arr2, size2, unionArr);

    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
