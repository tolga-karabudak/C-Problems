#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findMind(int *arr, int size,int start){
	int min=*(arr+start);
	int min_i=start;;
	for(int i=start;i<size;i++)
	{
		if(*(arr+i)<min)
		{
			min=*(arr+i);
			min_i=i;
		}
	}

	return(min_i);
}

void selection_sort(int *arr,int size)
{
	for(int i=0;i<size-1;i++)
	{
		int min_size=findMind(arr,size,i);
		
		int temp=*(arr+i);
		*(arr+i)=*(arr+min_size);
		*(arr+min_size)=temp;		
	}
}

int main()
{
	int arr[]={32,12,56,66,1,3,98,23,322,-1};
	int size=(sizeof arr)/4;
	int sorted[size];	


	printf("*************\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
	selection_sort(arr,size);
	printf("*************\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
	
}
