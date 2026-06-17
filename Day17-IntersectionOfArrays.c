#include <stdio.h>
#define MAX_VALUE 100

int main() {
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {1, 2, 5, 6, 7};
    int size1 = 5, size2 = 5;
    int hash[MAX_VALUE] = {0};
    int i;
    
    printf("Array 1: ");
    for(i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
        hash[arr1[i]] = 1; 
    }
    printf("<br>");
    
    printf("Array 2: ");
    for(i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("<br>");
    
    printf("Intersection: ");
    for(i = 0; i < size2; i++) {
        if(hash[arr2[i]] == 1) {
            printf("%d ", arr2[i]);
            hash[arr2[i]] = 0; 
        }
    }
    printf("<br>");
    
    return 0;
}