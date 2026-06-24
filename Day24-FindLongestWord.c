#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 1024

int main() {
    char str[MAX_LIMIT];
    char longest_word[MAX_LIMIT] = "";
    int max_len = 0;

    printf("Enter a sentence: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove the trailing newline character, if present
        str[strcspn(str, "\n")] = 0;

        char temp_word[MAX_LIMIT];
        int temp_len = 0;
        int i = 0;

        while (1) {
            // Check if we hit the end of the string or a space
            if (str[i] == '\0' || isspace(str[i])) {
                if (temp_len > max_len) {
                    max_len = temp_len;
                    strncpy(longest_word, temp_word, temp_len);
                    longest_word[temp_len] = '\0'; // Null-terminate the longest word
                }
                
                if (str[i] == '\0') {
                    break;
                }
                temp_len = 0; // Reset temp length for the next word
            } else {
                // Ignore punctuation marks to strictly count word letters
                if (!ispunct(str[i])) {
                    if (temp_len < MAX_LIMIT - 1) {
                        temp_word[temp_len++] = str[i];
                    }
                }
            }
            i++;
        }

        if (max_len > 0) {
            printf("The longest word is: %s\n", longest_word);
            printf("Length: %d\n", max_len);
        } else {
            printf("No words found.\n");
        }
    }

    return 0;
}
