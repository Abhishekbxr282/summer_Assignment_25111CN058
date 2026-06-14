#include<stdio.h>
int main(){
    int a[10];
    int i,k=0;
    int num;

    printf("Enter the value in array \n");
    for(i=0;i<=9;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number \n");
    scanf("%d",&num);
         for(i=0;i<=9;i++){
            if(a[i]==num){
                k=1;
                break;
            }
         }
         if(k==1){
             printf("no found on location %d",i);
         }
         else{
             printf("not found");
         }
         return 0;
}
