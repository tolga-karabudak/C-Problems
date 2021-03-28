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
	for(int i=0;i<size;i++)
	{
		int min_size=findMind(arr,size,i);
		
		int temp=*(arr+i);
		*(arr+i)=*(arr+min_size);
		*(arr+min_size)=temp;		
	}
}


void buble_sort(int arr[],int size){	
	for(int pass=1;pass<size-1;pass++){
		for(int k=0;k<size-pass;k++){
			if(arr[k]>arr[k+1]){
				int temp;
				temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			}
			
			
		}
	}
}

int main()
{
	int arr[50];
	int i=0;
	FILE *inp=fopen("points.txt","r");
	while(fscanf(inp,"%d",(arr+i))!=EOF)
	{
		i++;
	}
//	printf("%d\n",i);
//	for(int k=0;k<i;k++)
//		printf("%d\n",*(arr+k));
		
/*	selection_sort(arr,i);
	for(int a=0;a<i;a++)
	{
		printf("%d\n",arr[a]);
	}
	
*/	buble_sort(arr,i);
	printf("Points: \n");
	printf("------ \n");
	for(int a=i-1;a>=0;a--)
		printf("%d\n",arr[a]);
}
