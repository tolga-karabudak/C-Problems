#include<stdio.h>
#include<math.h>
/* CENG104 LG5 
Author: Evren*/
int sum_div(int num, int divisor)
{
	int sum;

	if (divisor == 1)		//all numbers are divisible by 1
		sum = 1;
	else
		if (num % divisor == 0)
			sum = divisor + sum_div(num, divisor - 1);
		else
			sum = sum_div(num, divisor - 1);
	return sum;
}

int main(void)
{
	int number;

	printf("\nEnter a number: ");
	scanf("%d", &number);

	if (number == sum_div(number, number / 2))
		printf("%d is a perfect number!\n", number);
	else
		printf("%d is NOT a perfect number!\n", number);
	return 0;
}