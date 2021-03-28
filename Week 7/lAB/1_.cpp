#include<stdio.h>
#include<string.h>

int acker(int m,int n)
{
	int result;
	
	if(m==0)
		return n+1;
	else if(m>0&& n==0)
		return acker(m-1,1);
	else if(m>0&& n>0)
		return acker(m-1,(acker(m,n-1)));

	
	
}

int main()
{
	int m,n;
	printf("Enter a value of m: ");
	scanf("%d",&m);
	printf("Enter a value of n: ");
	scanf("%d",&n);
	printf("The result is %d",acker(m,n));
	
	
}
