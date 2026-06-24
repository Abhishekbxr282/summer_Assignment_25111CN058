#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int length = strlen(str);
    if (length < 2) {
        return;
    }

    int seen[256] = {0};
    int targetIndex = 0;

    for (int currentIndex = 0; currentIndex < length; currentIndex++) {
        unsigned char ch = str[currentIndex];
        if (seen[ch] == 0) {
            seen[ch] = 1;
            str[targetIndex] = str[currentIndex];
            targetIndex++;
        }
    }
    str[targetIndex] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
        
        removeDuplicates(str);
        
        printf("Result: %s\n", str);
    }

    return 0;
}
