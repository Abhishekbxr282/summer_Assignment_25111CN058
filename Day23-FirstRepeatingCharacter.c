#include <stdio.h>
#include <string.h>

char find_first_repeating(char *str) {
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
        if (count[(unsigned char)str[i]] > 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
        
        char result = find_first_repeating(str);
        
        if (result != '\0') {
            printf("The first repeating character is: %c\n", result);
        } else {
            printf("No repeating characters found.\n");
        }
    }
    
    return 0;
}
