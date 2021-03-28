#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int id, age, worked_hour; 
	double salary;
	char name[100];
}workers;

typedef struct{
	int id;
	char name[25];
	workers w[10];
}dep;





void read(FILE * inp,dep *d )
{	
	int k=0;
	while(fscanf(inp,"%d",&(d+k)->id)!=EOF)
	{
//		printf("%d",d[k].id);
		fscanf(inp," %[^\n]s",(d+k)->name);
//		printf("%s",&(d+k)->name);
		
		for(int i=0;i<3;i++)
		{
			fscanf(inp,"%d %s %d %d",&(d+k)->w[i].id,
			(d+k)->w[i].name,&(d+k)->w[i].age,
			&(d+k)->w[i].worked_hour);
		}
		k++;		
	}
}
void salary(dep *d)
{
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<3;i++)
		{
			if((d+k)->w[i].worked_hour>40)
			{
				(d+k)->w[i].salary=
				2*40+((d+k)->w[i].worked_hour-40)*5;
			}
			else
			{
					(d+k)->w[i].salary=(d+k)->w[i].worked_hour*2;
			}
		}
	}
}

void display (dep *d)
{
	for(int k=0;k<3;k++)
	{
		printf("INFORMATION OF A %s DEPARTMENT \n", (d+k)->name);
		printf("ID	NAME     AGE	HOURSWORKED	SALARY\n");
		printf("***     ****     ***    ***********     *********\n");
		for(int i=0;i<3;i++)
		{
			printf("%-7d %-8s %d %7d %19.2lf\n",(d+k)->w[i].id, (d+k)->w[i].name,(d+k)->w[i].age ,(d+k)->w[i].worked_hour, (d+k)->w[i].salary);
		}
		printf("\n");
	}
		
}


int main()
{
	FILE *inp=fopen("Employee.txt","r");
	if(inp==NULL)
		printf("***");
	else
	{
	dep d[3];
	read(inp,d);
	salary(d);
//	printf("%d",d[1].w[1].worked_hour);
//	printf("%.2lf",d[0].w[0].salary);
	display(d);
	}
	
	
	
	
	
	
	
	
	
}
