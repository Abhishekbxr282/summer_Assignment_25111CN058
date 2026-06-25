#include <stdio.h>
#include <string.h>

void sort_words(char words[][100], int count) {
    char temp[100];
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main() {
    int count;
    printf("Enter number of words: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        return 1;
    }

    char words[count][100];
    printf("Enter %d words:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%s", words[i]);
    }

    sort_words(words, count);

    printf("\nSorted words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
