#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
       
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }

    
    return -1; 
}

int main() {
    
    int arr[] = {1, 4, 6, 12, 18, 22, 38, 59, 72, 98};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
