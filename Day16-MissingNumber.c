#include <stdio.h>
int findMissingNumber(int arr[], int size) {
    
    int N = size + 1;
    
    int expectedSum = (N * (N + 1)) / 2;
    
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 3, 4, 2, 5, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missingNumber = findMissingNumber(arr, size);
    
    printf("The missing number is: %d\n", missingNumber);
    
    return 0;
}