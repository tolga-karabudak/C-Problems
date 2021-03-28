#include<stdio.h>
#include<string.h>

void listele(char *st,int *upper, int *lower, int *digit, int *space)
{
	char temp;
	
	for(int i=0;i<strlen(st);i++)
	{
		temp=st[i];
		if(temp>='a'&&temp<='z')
			*lower=*lower+1;		
		else if(temp>='A'&&temp<='Z')
			*upper+=1;
		else if(temp>='0'&&temp<='9')
			*digit+=1;
		else if(temp==' ')
			*space+=1;
	}
	

}



int main()
{
	char st[50];
	int upper=0,lower=0,digit=0,space=0;
	printf("Write sentence: ");
	gets(st);
	listele(st,&upper,&lower,&digit,&space);
	printf("Upper Letter: %d \n",upper);
	printf("lower Letter: %d \n",lower);
	printf("digit Letter: %d \n",digit);
	printf("Space Letter: %d \n",space);

	

	
	
}
