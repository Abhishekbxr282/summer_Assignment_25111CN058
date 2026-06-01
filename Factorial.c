#include <stdio.h>
int main () {
    long long num;
    int count = 0;
    printf("Enter an integer:");
    scanf("%11d", &num);

    do {
        num /= 10;
        count++;
    } while (num != 0);
    printf("Total digits : %d\n", count);
    
     return 0;

}


