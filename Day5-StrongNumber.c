
#include <stdio.h>
int main() {
	int num,count;
  printf("Enter the number:\n");
  scanf("%d",&num);

  printf("Factors of %d are\n",num);
  for(count = 1; count == 0)
  {
    if(num % count == 0)
    printf("%d\n",count);
  }
  return 0;
}