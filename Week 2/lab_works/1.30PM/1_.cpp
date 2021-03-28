#include<stdio.h>
typedef struct{
	char type[50];
	int model,price;
}cars_t;

int menu()
{
	int select;
	do{
	printf("According to:\n1.Type\n2.Model\n3.Price range\n4.EXIT\nEnter your choice: ");	
	scanf("%d",&select);
	}while(select<1|select>4);
	return select;	
}

int main()
{
	cars_t cr[20];
	FILE *inp=fopen("cars.txt","r");
	int counter=0;
	char c;
	while(fscanf(inp,"%[^0-9] %d %d ",&(cr+counter)->type,&(cr+counter)->model,&(cr+counter)->price)!=EOF)
	{
		counter++;
	}
	int select=menu();
	while(select!=4)
	{
		switch(select)
		{
			case 1:
				do{
					printf("Enter a type (P:Peugeot,M:Mercedes,H:Honda):");
					scanf("%s",&c);
				}while(c!='M'&&c!='P'&&c!='H');
				for(int i=0;i<counter;i++)						
				{
					if(c==(cr+i)->type[0])
				{
					printf("%s\t%d  %d\n",(cr+i)->type,(cr+i)->model,(cr+i)->price);
				}
				}		
				break;
			case 2:
				printf("Enter a model year: ");
				int year;
				scanf("%d",&year);
				for(int i=0;i<counter;i++)
				{
					if((cr+i)->model==year)
						printf("%-10s %d  %d\n",(cr+i)->type,(cr+i)->model,(cr+i)->price);		
				}	
				break;
			case 3:
				printf("\nEnter a price range: ");
				int r1,r2;
				do{
				scanf("%d %d",&r1,&r2);
				}while(r1>r2);
				for(int i=0;i<counter;i++)
				{
					if(r1<=(cr+i)->price&&(cr+i)->price<=r2)
						printf("%-10s %d  %d\n",(cr+i)->type,(cr+i)->model,(cr+i)->price);		
					
				}
				break;
		}	
		select=menu();
	
	}
}
