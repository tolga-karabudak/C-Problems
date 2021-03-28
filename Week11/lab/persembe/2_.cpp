#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linked_list.h"

int main()
{
	node_t *headp;
	headp=Getnode();
//	display_list(headp);
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	if(num!=-1)
	{
		add_beginning(headp,num);
	//	add_after(headp,num); 
	//	printf("%d\n",headp->data);
		printf("Enter a number: ");
		scanf("%d",&num);	
		while(num!=-1)
		{	
			add_after(headp,num);
		//	printf("%d\n",headp->next->data);
			printf("Enter a number: ");
			scanf("%d",&num);		
		}
	}
//	printf("%d\n",headp->data);
//	printf("%d\n",headp->next->data);
//	printf("%d\n",headp->next->next->data);
//	printf("%d\n",headp->next->next->next->data);
	
	display_list(headp);
	
}
