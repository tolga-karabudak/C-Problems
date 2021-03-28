#include<stdio.h>
#include<string.h>

int findFirst(char sent[100],char str[10])
{
	char *a=strstr(sent,str);
		if(a!=NULL)
			return a-sent;
			
		else
			return -1;
		
}

void del(char sent [100],char str[10],int index)
{
	int size1=strlen(str);
	int size2=strlen(sent);
	char nsent[100];
	if (index!=0)
	{
		strncpy(nsent,sent,index);
		strcat(nsent,(sent+index+size1));
	
	}
	else
	strcpy(nsent,(sent+index+size1));

	printf("\nThe new form of the sentence : %s",nsent);
	
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
	printf("%d",a);
	if(a!=-1)
	printf("The first occurence of the string<%s> is :%d",str,a);
	else
	printf("\nThe sentence does NOT contain the string <%s>",str); 
	del(sent,str,a);
	
	
}
