#include <stdio.h>
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    
    int array1[] = {1, 2, 4, 5, 6, 2, 9};
    int array2[] = {2, 3, 5, 7, 9, 9, 12};
    
    int len1 = sizeof(array1) / sizeof(array1[0]);
    int len2 = sizeof(array2) / sizeof(array2[0]);
    
    int common[100];
    int k = 0; 
    
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            
            if (array1[i] == array2[j]) {
                if (!isDuplicate(common, k, array1[i])) {
                    common[k] = array1[i];
                    k++;
                }
            }
        }
    }

    if (k > 0) {
        printf("Common elements are: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", common[i]);
        }
        printf("\n");
    } else {
        printf("No common elements found.\n");
    }

    return 0;
}
