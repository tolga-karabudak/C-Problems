#include<stdio.h>
#include<string.h>
#include"queue_int.h"

void display(queue_t depo)
{
	info temp;
	temp=remove(&depo);

	while(!is_empty_q(&depo))
	{
		printf("%-10s%10d\n",temp.name,temp.id);
		temp=remove(&depo);
	}
}

void the_day(queue_t depo)
{
	info temp,max;
	max=remove(&depo);
	while(!is_empty_q(&depo))
	{
		temp=remove(&depo);
		if(temp.id>max.id)
			max=temp;
	}
	printf("\nThe waiter/waitress of the day:\n");
	printf("%s       %d",max.name,max.id);
	
}
int main()
{
	info temp;
	queue_t depo;
	initialize_q(&depo);
	FILE *inp=fopen("staff.txt","r");
	

	while(fscanf(inp,"%s%d",temp.name,&temp.id)!=EOF)
	{
//		printf("%s      %d\n",temp.name,temp.id);
		insert(&depo,temp);
	}
	display(depo);
	the_day(depo);
}
