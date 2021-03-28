#include<stdio.h>
void readFile(FILE *inp, char arr[8][10])
{
	char letter;
	int i=0;
	int j=0;
	inp=fopen("palindrome.txt","r");
	if(inp== NULL)
		printf("Fýle ca not opened!!");
	else
	{
		int status=fscanf(inp,"%c",&letter);
		while(status!=EOF)
		{
			if(letter!='\n')
			{
				arr[i][j]=letter;
				j++;
				status=fscanf(inp,"%c",&letter);
			}
			else
			{
				i++;
				j=0;
				status=fscanf(inp,"%c",&letter);
			}
		}
	}
}
int findSize(char arr[10])
{
	int size=0;
	for(int i=0;i<10;i++)
	{
		if(arr[i]>=65&&arr[i]<=90||arr[i]>=97&&arr[i]<=122)
		size++;
	}
	return size;
}
int isPalindrome(char arr[10], int size)
{
	int k=0;
	if(size%2==0)
	{
		for(int i=0;i<=((size-1)/2);i++)
		{
			if(arr[i]==arr[size-1-i])
				k++;
		}
		if(k==((size/2)))
			return 1;
		else
			return 0;
	}
	else
	{
		for(int i=0;i<(size/2);i++)
		{
			if(arr[i]==arr[size-1-i])
				k++;
		}
		if(k==((size-1)/2))
			return 1;
		else
			return 0;
	}
}

int main()
{	
	int size;
	FILE *inp;
	char words[8][10];
	readFile(inp,words);
	printf("INDEXES\n");
	for(int i=0;i<8;i++)
	{
		size=findSize(words[i]);
		if(isPalindrome(words[i],size))
			printf("%d\n",i);
		else
			printf("Not palindrome\n");		
	}	
	return 0;
}
