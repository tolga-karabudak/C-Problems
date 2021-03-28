#include<stdio.h>
#include<string.h>
#include"stack_char.h"


int main()
{
	stack_t depo;
	initialize_s(&depo);
	char exp[100];
	gets(exp);
	int i=0;
	int flag=1;
	while(*(exp+i)!='\0'&&flag)
	{
		if(*(exp+i)=='(')
			push(&depo,*(exp+i));
		else if(is_empty_s(&depo)&&*(exp+i)==')')
			flag=0;
		else if(!is_empty_s(&depo)&&*(exp+i)==')')
			pop(&depo);	
		i++;		
	}
	if(flag==1||!is_empty_s(&depo))
		printf("\n\nHataaaaaa...!!!");	
}
