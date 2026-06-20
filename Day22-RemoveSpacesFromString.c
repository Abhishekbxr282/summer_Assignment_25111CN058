#include <stdio.h>

void removeSpaces(char *str) {
    int readIndex = 0;
    int writeIndex = 0;

    while (str[readIndex] != '\0') {
        
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    
    str[writeIndex] = '\0';
}

int main() {
    
    char text[] = "C P r o g r a m m i n g";

    printf("Original string: '%s'\n", text);

    removeSpaces(text);

    printf("Modified string: '%s'\n", text);

    return 0;
}
