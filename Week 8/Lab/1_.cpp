#include<string.h>
#include<stdio.h>
#include"stack_int.h"

void display(stack_t info)
{
	int item;
	while(!is_empty_s(&info))
	{
		item=pop(&info);
		printf("%d\n",item);
	}
	
}


int main()
{
	stack_t info;
	initialize_s(&info);
	int emp=is_empty_s(&info);
	printf("%d",emp);
	int item;
	for(int i=0;i<6;i++)
	{
		if(!is_full_s(&info))
		{
			item;
			printf("Enter a value: ");
			scanf("%d",&item);
			push(&info,item);
		}
	}
	printf("Stack Content:\n");
	display(info);
	
	printf("After swap:\n");
	int temp=pop(&info);
	int temp2=pop(&info);
	push(&info,temp);
	push(&info,temp2);
//	int temp=info.data[5];
//	info.data[5]=info.data[4];
//	info.data[4]=temp;
	for(int i=5;i>=0;i--)
	{
		temp=pop(&info);
		printf("%d\n",temp);
	}
	
	
}
