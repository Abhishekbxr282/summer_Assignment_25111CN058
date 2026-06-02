#include <stdio.h>
int main () {
   int i,rev = 0;
   printf("Enter the number to find reverse:");
   scanf("%d",&i);
    while(i > 0){
        rev = (rev*10)+ i%10;
        i = i/10;
    }
    printf("\nReverse = %d",rev);
     return 0;

}


