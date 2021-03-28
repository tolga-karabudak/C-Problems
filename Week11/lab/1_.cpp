#include<stdio.h>
#include<string.h>
#include"kadir.h"

void display(queue_t depo)
{
	if(!is_empty_q(&depo))
	{
		asd deneme;
	int k=depo.counter;
	deneme=remove(&depo);
	for (int i=0;i<k;i++)
	{
		printf("%c %.2lf\n",deneme.c,deneme.amount);
		deneme=remove(&depo);
	}
	}
	

	
}

int main()
{
	
	queue_t a,b,c,depo;
	initialize_q(&a);
	initialize_q(&b);
	initialize_q(&c);
	initialize_q(&depo);
	int ca=0;
	int cb=0;
	int cc=0;
	double payment;
	int cash=0;
	int v=0;
	FILE *inp=fopen("customers.bin","rb");
	QType temp;
	for(int i=0;i<19;i++)
	{
		fread(&temp,sizeof(asd),1,inp);
		if(temp.c!='P')
		{
			if(ca<cb&& ca<cc)
			{
				insert(&a,temp);
				ca++;
			}
			else if(cb<ca&&cb<cc)
			{
				insert(&b,temp);
				cb++;
			}
			else if(cc<ca&&cc<cb)
			{
				insert(&c,temp);
				cc++;
			}
			else if(ca==cb&&ca==cc)
			{
				insert(&a,temp);
				ca++;
			}
			else if(ca>cb&&cb==cc)
			{
				insert(&b,temp);
				cb++;
			}
			else if(cb>ca&&ca==cc)
			{
				insert(&a,temp);
				ca++;
			}
			else if(cc>cb&&cb==ca)
			{
				insert(&a,temp);
				ca++;
			}
			
			
			
			
			
			
			
			/*
			else if(ca>cb&&cb<cc)
			{
				insert(&b,temp);
				cb++;
			}
			else if(ca==cb&&ca<cc)
			{
				insert(&a,temp);
				ca++;
			}
			else if(ca>cb&&cb==cc)
			{
				insert(&b,temp);
				cb++;
			}*/			
		}
		else
		{
			if(temp.amount==1)
			{
				temp=remove(&a);
				ca--;
				payment+=temp.amount;		
			}
			if(temp.amount==2)
			{
				temp=remove(&b);
				cb--;
				payment+=temp.amount;	
			}
			if(temp.amount==3)
			{
				temp=remove(&c);
				cc--;	
				payment+=temp.amount;	
			}
			
			if(temp.c=='C')
			cash++;
			else
				v++;		
			
		}		
		
	}
	printf("Cash Desk 1\n");
	display(a);
	printf("\nCash Desk 2\n");
	display(b);
	printf("\nCash Desk 3\n");
	display(c);
	printf("\nCash: %d",cash);
	printf("\nVisa: %d",v);
	printf("\nTotal payment: %.2lf",payment);
	
	
	
}
