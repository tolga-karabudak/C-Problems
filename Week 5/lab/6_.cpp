#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int readBikeList(FILE *inp1,char b1[15][10])
{
	int i=0;
	while(fscanf(inp1,"%s",*(b1+i))!=EOF)
	{
		i++;
	}
	return i;
}
void shifdown(FILE *inp3,char b1[15][10],char b2[15][10],int sb1,int sb2)
{
	int size=sb1+sb2;
//	printf("%d",size);
	int bk1=0;
	int bk2=0;

	for(int i=0;i<size;i++)
	{	
		if(bk1>=sb1)
		{
			fprintf(inp3,"%s\n",b2[bk2]);
			bk2++;
		}
		else if(bk2>=sb2)
		{
			fprintf(inp3,"%s\n",b1[bk1]);
			bk1++;
		}
		else if(strcmp(b2[bk2],b1[bk1])>0)
		{
		//	printf("%s\n",b1[bk1]);
			fprintf(inp3,"%s\n",*(b1+bk1));
			bk1++;
		}
		else if(strcmp(b1[bk1],b2[bk2])>0)
		{
			fprintf(inp3,"%s\n",b2[bk2]);
			bk2++;
			
		}
		else if(strcmp(b2[bk2],b1[bk1])<0)
		{
		//	printf("%s\n",b1[bk1]);
			fprintf(inp3,"%s\n",*(b2+bk2));
			bk2++;
		}
		else if(strcmp(b1[bk1],b2[bk2])<0)
		{
			fprintf(inp3,"%s\n",b1[bk1]);
			bk1++;
			
		}

		
			
		
	}
}


int main()
{
	FILE *inp1=fopen("bike1.txt","r");
	FILE *inp2=fopen("bike2.txt","r");
	FILE *inp3=fopen("bike3.txt","w");
	char b1[15][10];
	char b2[15][10];
	int i=0;
	int j=0;
/*	while(fscanf(inp1,"%s",*(b1+i))!=EOF)
	{
		i++;
	}
	
	while(fscanf(inp2,"%s",*(b2+j))!=EOF)
	{
		j++;
	}
//	printf("%d",j);*/
	int size1=readBikeList(inp1,b1);
	int size2=readBikeList(inp2,b2);
	/*for(int a=0;a<size1;a++)
		printf("%s\n",*(b1+a));
	for(int a=0;a<size2;a++)
		printf("%s\n",*(b2+a));*/
	shifdown(inp3,b1,b2,size1,size2);
	
}
