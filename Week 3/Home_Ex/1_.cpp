#include<stdio.h>
#include <stdlib.h>
//#include<string.h>

typedef struct{
	int ch,word;
}info;

void read(FILE *inp,char str[10][50],int line)
{
	int j;
	for(int i=0;i<line;i++)
	{
		fscanf(inp,"%[^\n] ",str[i]);
//		printf("%d\n",i);
//		j=0;
//		while(fscanf(inp,"%c",&str[i][j])!='\n')
//		for(j;(fscanf(inp,"%[^\n]",&str[i][j]))!='\n';j++);			
	}
	
	
}


int main()
{	char str [10][50];
	FILE *inp=fopen("qwe.txt","r");
	int line=1;
	char temp;
	while(fscanf(inp,"%c",&temp)!=EOF)
	{
		if(temp=='\n')
			line++;
	}
	fclose(inp);
	printf("satir sayisi: %d\n",line);
	inp=fopen("qwe.txt","r");
	read(inp,str,line);
	for(int w=0;w<line;w++)
		printf("%s\n",*(str+w));
	info *inf;
	inf=(info*)malloc(line*sizeof(info));
	int ch1;
	int wr1;
	for(int a=0;a<line;a++)
	{
		int k=0;
		ch1=0;
		wr1=1;
		while(*(*(str+a)+k)!='\0')
		{			
			if(*(*(str+a)+k)>='A'&&*(*(str+a)+k)<='z')
				ch1++;
			else if(*(*(str+a)+k)==' ')
				wr1++;
			k++;
		}
		printf("%d. satir %d harf %d kelime.\n",a+1,ch1,wr1);
	}

		
	
/*	char str[3][50];
	
	printf("\nEnter a string: ");
	scanf("%[^\n]",str);
	int ch=0,w=0,i=0;
	printf("%s\n",str);
	while(*(str+i))
	{
		if(*(str+i)!=' ')
			ch++;
		else
			w++;
		i++;
	}
	printf("character: %d\n",ch);
	printf("word: %d",w);
*/
}
