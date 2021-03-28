#include<stdio.h>
#include<string.h>
#include"stack_int.h"

int remove_max(stack_t *s)
{
	stack_t temp;
	initialize_s(&temp);
	int max,num;
	max=pop(s);
	push(&temp,max);
	while(!is_empty_s(s))
	{
		num=pop(s);
		push(&temp,num);
		if(num>max)
			max=num;
	}	
	 
	while(!is_empty_s(&temp))
	{
		num=pop(&temp);
		if(num!=max)
			push(s,num);
	}
	return max;
}


int main()
{
	stack_t depo;
	initialize_s(&depo);
	push(&depo,3);
	push(&depo,5);
	push(&depo,12);
	push(&depo,2);
	push(&depo,7);
	push(&depo,9);
	remove_max(&depo);
	while(!is_empty_s(&depo))
		printf("%d\n",pop(&depo));
	
	
	
}
