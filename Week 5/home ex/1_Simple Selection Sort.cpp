#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findMind(int *arr, int size){
	int min=*arr;
	int min_i=0;;
	for(int i=1;i<size;i++)
	{
		if(*(arr+i)<min)
		{
			min=*(arr+i);
			min_i=i;
		}
	}

	return(min_i);
}

void simple_selection_sort(int *arr,int *sorted,int size)
{
	for(int i=0;i<size;i++)
	{
		
		*(sorted+i)=*(arr+(findMind(arr,size)));
		*(arr+(findMind(arr,size)))=999;
		
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
	simple_selection_sort(arr,sorted,size);
	printf("*************\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\n",sorted[i]);
	}
	
}
