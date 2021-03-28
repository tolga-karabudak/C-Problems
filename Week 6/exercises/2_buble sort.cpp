#include<stdio.h>
#include<string.h>

void bublesort(int *arr,int size)
{
	int pass=1;
	
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-pass;j++)
		{
			if(*(arr+j)<*(arr+j+1))
			{
				int temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
	}
}

int binarSearch(int *arr,int sNum,int top,int bottom)
{

	while(top<=bottom)
	{
		int middle=bottom+top/2;
		if(sNum==*(arr+middle))
			return middle;
		else if(sNum<*(arr+middle))
			top=middle+1;
		else
			bottom=middle-1;
	}
	return -1;
	
}



int main()
{
	FILE *inp=fopen("numbers.txt","r");
	int arr[100];
	int size=0;
	while(fscanf(inp,"%d",(arr+size))!=EOF)
		size++;
		
	bublesort(arr,size);
	for(int i=0;i<size;i++)
	{
		printf("%d\n",*(arr+i));
	}
		
	int num;scanf("%d",&num);
	int index=binarSearch(arr,num,0,size-1);
	printf("\n\n%d",index);
	
	
}
