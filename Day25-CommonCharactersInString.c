#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void findCommonCharacters(char *str1, char *str2) {
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int i, common_count = 0;

  
    for (i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }

    for (i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    printf("Common characters: ");

    for (i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            
            int min_freq = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
            
            for (int j = 0; j < min_freq; j++) {
                printf("%c ", i);
                common_count++;
            }
        }
    }

    if (common_count == 0) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 
    findCommonCharacters(str1, str2);

    return 0;
}
