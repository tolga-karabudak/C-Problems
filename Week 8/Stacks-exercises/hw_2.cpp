#include<stdio.h>
#include<string.h>
#include"stack_char.h"

int main()
{
	printf("Write a sentence: ");
	stack_t sentence;
	initialize_s(&sentence);
	char ch[100];
	scanf("%[^\n]n \n",ch);
//	printf("%s",ch);
//	printf("a");
	int i=0;
	while(ch[i]!='\0')
	{
		push(&sentence,ch[i]);
		if(ch[i]==' ')
			{
				while(!is_empty_s(&sentence))
				{
				printf("%c",pop(&sentence));
				}	
			}
		i++;
		}
	
	push(&sentence,' ');
	while(!is_empty_s(&sentence))
	{
		printf("%c",pop(&sentence));
	}
	
	
	
}
