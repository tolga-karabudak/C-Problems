#include<stdio.h>
#include<string.h>

double factRec(int n)
{
	double result;
	if(n<=1)
		result=1;
	else
		result=n*factRec(n-1);
	return result;
}

double arrSum(int arr[],int size)
{
	double sum;
	if(size==1)
		sum= arr[0];
	else
		sum=arr[size-1]+arrSum(arr,size-1);
	
	return sum;
}

int stlen(char str[])
{
	int len;
	if(*(str)=='\0')
		len=0;
	else
		len=1+stlen((str+1));
	
	return len;
}

int fib(int n)
{
	int sum;
 if(n==1)
 	sum=1;
else if(n==2)
	sum=1;
else
	sum=fib(n-2)+fib(n-1);
return sum;
}

void func(int n)
{
	if (n < 2)
		printf("%d", n);
	else
	{
		func(n / 2);
		printf("--%d", n % 2);
	}
}
int main()
{
	int num;
//	scanf("%d",&num);
//	printf("%.2lf",factRec(num));
//	int arr[]={1,2,3,4};
//	printf("%lf",arrSum(arr,4));
//	printf("%d",fib(num));
//	char st[100];
//	gets(st);
//	printf("%d",stlen(st));
	int x=5;
	func(x);
	
	
}
