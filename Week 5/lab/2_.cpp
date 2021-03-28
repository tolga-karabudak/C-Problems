
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	char text[100];
	char st[10];
	printf("Enter a text: ");
	scanf("%[^\n]s",text);
	printf("Enter a string: ");
	scanf("%s",st);
	int ssize=strlen(st);
	int size=strlen(text);
	printf("The old text : %s\n",text);
	for(int i=0;i<size;i++)
	{
		if(i==0&&strncmp(&text[i],st,ssize)==0)
		{
			int k=i;
			text[k++]='*';
			for(int a=0;a<ssize-1;a++)
			{
				text[k]=' ';
				k++;
			}
		}
		else if(text[i-1]==' '&&strncmp(&text[i],st,ssize)==0)
		{
			int k=i;
			text[k++]='*';
			for(int a=0;a<ssize-1;a++)
			{
				text[k]=' ';
				k++;
			}
		}
		else if(strncmp(&text[i],st,ssize)==0&&text[i+ssize]==' ')
		{
			int k=i;
			text[k++]='*';
			for(int a=0;a<ssize-1;a++)
			{
				text[k]=' ';
				k++;
			}
		}
		else if(strncmp(&text[i],st,ssize)==0&&text[i+ssize]=='\0')
		{
			int k=i;
			text[k++]='*';
			for(int a=0;a<ssize-1;a++)
			{
				text[k]=' ';
				k++;
			}
		}
	}

	printf("The new text: %s",text);
	
	
	
	
	
	
}
