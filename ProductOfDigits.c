#include <stdio.h>
int main() {
   int i,x,rev=0;
   printf("\nEnter no. to check ");
   scanf("%d",&i);
   x=i;
   while(i>0)
   {
    rev = (rev*10)+i%10;
    i= i/10;
   }
   if(rev==x)
     printf("Palindrome");
    else
     printf("Not Palindome");
   return 0;
    }



