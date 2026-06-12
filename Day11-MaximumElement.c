#include <stdio.h>

void max(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) { 
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
    printf("Max Element = %d\n", a[n - 1]);
}

int main() {
    int arr[100], num;
    printf("Enter total number of elements: ");
    scanf("%d", &num);
    
    printf("Enter elements one by one with space b/w them: ");
    for (int j = 0; j < num; j++) {
        scanf("%d", &arr[j]);
    }
    
    max(arr, num); 
    
    
    return 0;
}
