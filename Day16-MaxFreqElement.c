#include <stdio.h>
int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int max_element = arr[0];
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }

        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("The element with the maximum frequency is: %d\n", max_element);
    printf("It appears %d times.\n", max_count);

    return 0;
}