#include <stdio.h>
/* CENG104 LG5 
Author: Evren*/
int ackermann(int m, int n);

int main()
{
	int	m, n;

	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("Enter the value of n: ");
	scanf("%d", &n);

	if (m >= 0 && n >= 0)
		printf("\nThe result is %d\n", ackermann(m, n));
	else
		printf("\nThe value of both m & n had to be positive values. Exiting.\n");

	return 0;
}

int ackermann(int m, int n)
{
	//if num is 0 then n should be increased
	if (m == 0)
		return n + 1;
	else		
		if (n == 0)
			return ackermann(m - 1, 1);
		else
			return ackermann(m - 1, ackermann(m, n - 1));
}