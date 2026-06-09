#include <stdio.h>

int main() {
    int n;
    long long a = 0;
    long long b = 1;
    long long next;

    printf("Enter the position (n): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n == 0) {
        printf("The 0th Fibonacci term is 0\n");
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("The %dth Fibonacci term is %lld\n", n, b);

    return 0;
}
