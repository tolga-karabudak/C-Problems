#include<stdio.h>
#include<string.h>

int findFirst(char sent[100],char str[10])
{
	int size=strlen(sent);
	char *a=strstr(sent,str);
		if(a!=NULL)
			return a-sent;
			
		else
			return -1;
		
}


int main()
{
	char sent[100];
	printf("Enter a sentence: ");
	gets(sent);
	char str[10];
	printf("Enter a string: ");
	scanf("%s",str);
	int a=findFirst(sent,str);
	if(a!=-1)
	printf("The first occurence of the string<%s> is :%d",str,a);
	else
	printf("The sentence does NOT contain the string <%s>",str); 
	
	
}
