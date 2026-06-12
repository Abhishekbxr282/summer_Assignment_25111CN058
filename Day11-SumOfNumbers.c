#include <stdio.h>
int main(){
    long long n,sum;
    printf("Enter a positive integer:");
    scanf("%11d",&n);
    
    if(n < 0) {
        printf("Invalid input.Please enter a positive number.\n");

    }   else{
        sum = (n * (n + 1))/2;
        printf("Sum of first %11d naturalnumbers is: %11d\n",n, sum );
        }
            return 0;   

}