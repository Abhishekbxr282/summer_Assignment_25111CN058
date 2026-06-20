#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str); 

    reverseString(str);

    printf("Reversed string: %s\n", str);
    return 0;
}
