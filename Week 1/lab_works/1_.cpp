#include<stdio.h>
void disp_one(int arr[4])
{
	
	for(int i=0;i<4;i++)
	{
		printf("%3d",arr[i]);
	}
	
	
}

void disp_two(int arr[4][4])
{
	printf("   Matrix is: \n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
}

int find_max(int arr[4][4])
{
	int max=arr[0][0];
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(arr[i][j]>max)
			max=arr[i][j];
		}
	}
	return max;
}

int product(int arr[4])
{
	int prd=1;
	for(int i=0;i<4;i++)
	{
		prd=prd*arr[i];
	}
	return prd;	
}

int main()
{
	FILE *inp;
	inp=fopen("num.txt","r");
	int array_two[4][4];
	
	if (inp==NULL)
	printf("Fýle can not opened!!");
	else
	{
		for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
		{
			fscanf(inp,"%d",&array_two[i][j]);
		}
	}	
	}
	int b=0;
	int array_one[4];
	for(int i=0;i<4;i++)
	{	
		for(int j=0;j<4;j++)
		{
			if(i==j)
			array_one[b]=array_two[i][j];
		}
		b++;
	}
	
	disp_two(array_two);
	printf("Diagonal is:\n");
	disp_one(array_one);
	printf("\nThe maximum number of the array is :%3d",find_max(array_two));
	
	printf("\n Product : %d",product(array_one));
	
	return 0;
}
