#include<stdio.h>
#include<string.h>
void word_reverse(char *str,int size)
{	int ilk=0;
	int i=size;
	int temp;
	while(i>=0)	
	{
		
		if(str[i-1]>='a'&&str[i-1]<='z')
		{
//							printf("%d-",i-1);
			//printf("%c",str[i-1]);
			i--;
//			printf("yeni: %d",i-1);
		
		}
		
		else if(str[i-1]==' '|| i==0)
		{	
			
	//	printf("else %d",i);
			if(ilk==0)			
			{	
				temp=size;	
			}

//			printf("TEmp %d",temp);
		//	printf("%d\n",temp);
		//				printf("%d",i);
			for(int k=i;k<temp;k++)
			{
				printf("%c",str[k]);
			}
			ilk=1;
			printf(" ");
			i--;
			temp=i;	
		//	printf("%d",i);
		//	printf("%c",str[i]);
		}	
	}
}

int main()
{	char str[100];
	printf("Write a sentence: ");
	scanf("%[^\n]s",str);
	printf("%s\n",str);
	int size=strlen(str);
//	printf("%d\n",size);
//	printf("%c\n",str[size-1]);
//	printf("%d",size);
	word_reverse(str,size);

	
}
