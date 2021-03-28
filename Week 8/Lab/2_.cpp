#include<string.h>
#include<stdio.h>
#include"stack_int.h"

int palindrome(stack_t info, char temp[50])
{

		int k=info.top;
		
		for(int i=0;i<k;i++)
		{
			char tmp=pop(&info);
			if(tmp!=temp[i])
				return 0;
		}
		
		return 1;
		
		
	
}

int main()
{
	stack_t info;
	
	FILE *inp=fopen("palindrome.txt","r");
	char temp[50];
	
	while(fscanf(inp,"%[^\n]\n",temp)!=EOF)
	{	
		initialize_s(&info);
//		printf("%s\n",temp);
		int size=strlen(temp);
	//	printf("%d\n",size);
		for (int i=0;i<size;i++)		
			push(&info,temp[i]);
		int flag=palindrome(info,temp);
		if(flag==1)
			printf("%s\n",temp);		
		
	}
	
	
	
	
	
	
}
