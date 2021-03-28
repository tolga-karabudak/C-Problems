#include<stdio.h>


int main()
{
	char c;
	int harf=0;
	int kelime=0;
	scanf("%c",&c);
	while(c!='\n')
	{
		harf++;
		if(c==' ')
			kelime++;
		scanf("%c",&c);
		if(c=='\n')
			kelime++;
	
	}
	
	
	
	printf("Harf: %d--Kelime: %d",harf,kelime);
	
	
}
