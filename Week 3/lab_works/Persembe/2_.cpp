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
		fscanf(inp,"%[^-]",(info+counter)->surname);
//		printf("% s\n",(info+counter)->name);
		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
		/*fscanf(inp,"%d",&tmp);	
		printf("%d\n",tmp);
		fscanf(inp,"%c",&temp);	
		printf("%c\n",temp);
		fscanf(inp,"%d",&(info+counter)->date_m);	
		printf("%02d\n",tmp);*/
//		printf("%d.%d.%d\n",(info+counter)->date_d,(info+counter)->date_m,(info+counter)->date_y);
		fscanf(inp,"%d%c%d%c%d",&(info+counter)->date_d,&temp,&(info+counter)->date_m,&temp,&(info+counter)->date_y);
//		printf("%02d.%02d.%02d\n",(info+counter)->date_d,(info+counter)->date_m,(info+counter)->date_y);
		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
//		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
		fscanf(inp,"%[^\n]",(info+counter)->store_name);
//		printf("%s\n",(info+counter)->store_name);
//		printf("%d\n",counter);
		fscanf(inp,"%c",&temp);	
//		printf("%c\n",temp);
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
