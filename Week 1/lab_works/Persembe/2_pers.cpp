#include<stdio.h>

void disOne(int arr[4])
{
	for(int k=0;k<4;k++)
		printf("%-5d",arr[k]);
}
void dispTwo(int arr[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		printf("%-5d",arr[i][j]);
	printf("\n");
	}
}
int dot_product(int arrM[4],int arrV[4])
{
	int product=0;
	for(int i=0;i<4;i++)
	{
		product+=arrM[i]*arrV[i];
	}
	return product;
}
int main()
{
	FILE *inp;
	inp=fopen("matrix.txt","r");
	int matrix[4][4];
	int vector[4];
	
	if(inp==NULL)
		printf("File can not opened!!");
	else
	{		

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				fscanf(inp,"%d",&matrix[i][j]);
			}		
		}
		
		for(int k=0;k<4;k++)
		{
			fscanf(inp,"%d",&vector[k]);				
		}		
		
	}
	printf("The matrix is: \n");
	dispTwo(matrix);
	printf("\nThe vector is: \n");
	disOne(vector);
	printf("\n\nThe product is: \n");
	for(int i=0;i<4;i++)
		printf("%d\n",dot_product(matrix[i],vector));
}
