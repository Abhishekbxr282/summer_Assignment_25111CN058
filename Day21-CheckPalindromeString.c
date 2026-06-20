#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left = 0;
    int right;
    int isPalindrome = 1; 
    printf("Enter a string: ");
    scanf("%99s", str);

    right = strlen(str) - 1;

    while (right > left) {
        if (str[left] != str[right]) {
            isPalindrome = 0; 
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
