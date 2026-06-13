#include<stdio.h>
int main(){
    int a[10],i;
    for(i=0;i<10;i++)
{
    printf("\nEnter Number:");
    scanf("%d",&a[i]);
}
printf("\nArray elements are:");
for(i=0;i<10;i++)
printf("\n%d",&a[i]);
return 0;
}