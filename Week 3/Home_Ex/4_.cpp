#include<stdio.h>
#include<string.h>

void inverse(char st[][50],int j)
{
	for(int i=strlen(st[j]);i>=0;i--)
	{
		if(st[j][i] !=NULL)
		if(st[j][i] !=NULL)
		printf("%c",st[j][i]);
	}
	printf("\n");
}

int main()
{
	
	char st[2][50];
	
	for(int i=0;i<2;i++)
	{
		gets(st[i]);
//		puts(st[i]);
		inverse(st,i);		
	}
	for(int i=0;i<2;i++)
	{
		
		
	}
	
}
