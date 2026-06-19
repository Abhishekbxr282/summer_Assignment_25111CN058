
#include <stdio.h>
int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], sum[r][c];
    
    
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
            if (j == c - 1) printf("\n");
        }
    return 0;
}
