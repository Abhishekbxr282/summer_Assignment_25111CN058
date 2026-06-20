#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows/cols for Matrix 1 & 2: ");
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    if (c1 != r2) {
        printf("Error! Matrix dimensions invalid for multiplication.\n");
        return 1;
    }

    int m1[r1][c1], m2[r2][c2], res[r1][c2];
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 0;
}
