#include<stdio.h>
#include<string.h>

typedef struct{
	char name[12],surname[25],store_name[25];
	int date_d,date_m,date_y;
	int x;
}customer_t;




int main()
{
	FILE *inp=fopen("customers.txt","r");
	customer_t info[10];
	int counter=0;
	char temp;
	int tmp;
	
	while(fscanf(inp,"%s",(info+counter)->name)!=EOF)
	{
		fscanf(inp,"%[^-]--%d/%d/%d-- %[^\n]\n",(info+counter)->surname,
		&(info+counter)->date_d,&(info+counter)->date_m,&(info+counter)->date_y,
		(info+counter)->store_name);
//		
		counter++;

	}
//	printf("%d\n",counter);
//	char a='-';
//	printf("%d",a);
	printf(" AWARD WINNIG CUSTOMERS\n");
	printf(" ------------------------------------\n");
	for(int i=0;i<counter;i++)
	{
		printf(" %02d/%02d ",(info+i)->date_d,(info+i)->date_m);
		if(strlen((info+i)->name)+strlen((info+i)->surname)>12)
		{
//			
			printf("%c.%-25s",(info+i)->name[0],(info+i)->surname);
		}
		else
		{
			printf("%s",(info+i)->name);
			printf("%-23s",(info+i)->surname);
		}
		printf("%s\n",(info+i)->store_name);
	}
	
//	fscanf(inp,"[^/]",info+counter)->date_d)
	
}
