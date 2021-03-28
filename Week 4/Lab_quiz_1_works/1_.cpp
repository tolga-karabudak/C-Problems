#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap (int *x, int *y)
{ int temp;
temp = *x;
*x = *y;
*y = temp;
}

int main()
{		
	/*int first = 5;
	int second = 7;
	printf("first = %d second = %d\n", first, second);
	swap(&first, &second);
	printf("first = %d second = %d\n", first, second);
	return(0);*/
	
	
	
/*	int table[2][4];
	table[0][0]=1;
	printf("%d\n",table);
	printf("%d\n",&table[0]);
	printf("%d\n",&table[0][0]);
	printf("%d\n",*table);
	printf("%d\n",((*(table+0))+0));
	printf("%d\n",*((*(table+0))+0));
	printf("%d\n",**table);
	printf("*********\n");
	printf("%d\n",(table+1));
	printf("%d\n",*(table+1));
	printf("%d\n",table[1]);
	printf("%d");*/
	
	int arr1[1][2];
	

	int nums[3][3] = {
	{75, 50, 25},
	{15, 10, 5},
	{ 3, 2, 1}
	};
	nums[0][2]=3;
	
	printf("%d\n",*nums+2);
	printf("%d\n",*(nums)+2);
	printf("%d\n",*(*nums+2));
	printf("%d\n",*(*(nums)+2));
	
	
	
	
	
	
	
	
	
}

