
#include <stdio.h>
int main() {
	int num, temp, remainder, sum = 0, fact, i;

	printf("Enter a number: ");
	scanf("%d", &num);
	temp = num;
	while (temp > 0) {

		remainder = temp % 10;

		fact = 1;

		i = 1;
		
		while (i <= remainder) {
			fact *= i;
			i++;
		}
       
		sum += fact;
		
		temp /= 10;   
	}

	if (sum == num) {
		printf("%d is a strong number.\n", num);
	} else {
		printf("%d is not a strong number.\n", num);
	}

	return 0;
}