#include<string.h>
#include<stdio.h>
#include"stack_int.h"


void move_nth_bottom (stack_t *s, int n)
{
	stack_t temp;
	initialize_s(&temp);
	int ct=0;
	int num;

	while(ct<n)
	{
		num=pop(s);
		push(&temp,num);
//		printf("%d",num);
		ct++;
	}
	pop(&temp);
//	printf("\n")
	while(n<=s->top+1)
		push(&temp,pop(s));
	push(s,num);
//	pop(&temp);
	while(!is_empty_s(&temp))
		push(s,pop(&temp));
}
int main()
{
	stack_t depo;
	initialize_s(&depo);
	
	for(int i=1;i<6;i++)
		push(&depo,i);
//	while(!is_empty_s(&depo))
//		printf("%d\n",pop(&depo));
	move_nth_bottom(&depo,2);
	
	while(!is_empty_s(&depo))
	printf("%d\n",pop(&depo));

}	
