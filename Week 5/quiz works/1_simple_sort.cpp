#include<string.h>
#include<stdio.h>
int read(FILE *inp,int *arr)
{
	inp=fopen("kadir.txt","r");
	int i=0;
	while(fscanf(inp,"%d",arr+i)!=EOF)
		i++;
	return i;
}
int findMin(int *list,int start,int size)
{
	int min=*(list+start);
	int min_i=start;
	for(int i=start+1;i<size;i++)
	{
		if(*(list+i)<min)
		{
			min=*(list+i);
			min_i=i;
		}
	}
	return min_i;
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void sort(int *list,int size)
{
	for(int i=0;i<size-1;i++)
	{
		int min_i=findMin(list,i,size);
		swap((list+i),(list+min_i));
	}
}
int main()
{
	int list[25];
	FILE *inp;
	int num=read(inp,list);
//	printf("%d",*list);
	sort(list,num);
	
	for(int i=0;i<num;i++)
	{
		printf("%d\n",*(list+i));
	}
	
}
