#include<stdio.h>
#include<string.h>
#include"stack_char.h"

int main()
{	FILE *inp=fopen("seminer.txt","r");
	stack_t depo;
	initialize_s(&depo);
	info temp;
	while(fscanf(inp,"%d %[^\n]s\n",&temp.id,temp.name))
	{
		push(&depo,temp);
	}
	
	
	
}
