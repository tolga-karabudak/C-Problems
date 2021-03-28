#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int str_length(char *str)
{
char *p = str;
// Go until the end of the string
while (*p != '\0')
p++;
return (p - str);
}





int main()
{
	
	FILE *inp=fopen("words.txt","r");
	FILE *out=fopen("result.txt","w");
	
	char ch[10];
	int cntr=0;
	while(fscanf(inp,"%s",&ch)!=EOF)
	{
		cntr++;
		fprintf(out,"%s - %d\n",ch,str_length(ch));
		
	}
	printf("%d",cntr);
	
	
}
