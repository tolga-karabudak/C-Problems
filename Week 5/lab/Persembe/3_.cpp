#include<stdio.h>
#include<string.h>

typedef struct{
	int scn;
	char name[20];
	char surname[20];
}phone_t;
void read(FILE *inp1,FILE *inp2,phone_t *corp,phone_t *tech ,int *sizeFile1,int *sizeFile2)
{
	
	inp1=fopen("PhoneCorp.txt","r");
	inp2=fopen("PhoneTech.txt","r");
	int i=0;
	while(fscanf(inp1,"%d",&(corp+i)->scn)!=EOF)
	{
		fscanf(inp1,"%s",(corp+i)->name);
		fscanf(inp1,"%s",(corp+i)->surname);
		i++;
	}
	*sizeFile1=i;
	i=0;
	while(fscanf(inp2,"%d",&(tech+i)->scn)!=EOF)
	{
		fscanf(inp2,"%s",(tech+i)->name);
		fscanf(inp2,"%s",(tech+i)->surname);
		i++;
	}
	*sizeFile2=i;
	
}
void swap(phone_t *arr,int x,int y)
{
	int temp;
	temp=(arr+x)->scn;
	(arr+x)->scn=(arr+y)->scn;
	(arr+y)->scn=temp;
	char tempn[20];
	strcpy(tempn,(arr+x)->name);
	strcpy((arr+x)->name,(arr+y)->name);
	strcpy((arr+y)->name,tempn);
	char temps[20];
	strcpy(temps,(arr+x)->surname);
	strcpy((arr+x)->surname,(arr+y)->surname);
	strcpy((arr+y)->surname,temps);

}
int findMin(phone_t*arr,int sizefile,int start)
{
	int min= (arr+start)->scn;
	int min_i=start;
	for(int i=start;i<sizefile;i++)
	{
		if((arr+i)->scn<min)
		{
			min=(arr+i)->scn;
			min_i=i;
		}
	}
	return min_i;
}
void sort(phone_t *corp,phone_t *tech ,int sizeFile1,int sizeFile2)
{
	for(int i=0;i<sizeFile1-1;i++)
	{
		int minindex=findMin(corp,sizeFile1,i);
		swap(corp,i,minindex);	
	}
	for(int i=0;i<sizeFile2-1;i++)
	{
		int minindex=findMin(tech,sizeFile2,i);
		swap(tech,i,minindex);		
	}
}
void merge(phone_t *merged,phone_t *corp,phone_t *tech,int sizeFile1,int sizeFile2)
{
	int sizec=0;
	int sizet=0;
	for(int i=0;i<sizeFile1+sizeFile2;i++)
	{
		if(sizec>=sizeFile1)
		{
			(merged+i)->scn=(tech+sizet)->scn;
			strcpy((merged+i)->name,(tech+sizet)->name);
			strcpy((merged+i)->surname,(tech+sizet)->surname);
			sizet++;
		}
		else if(sizet>=sizeFile2)
		{
			(merged+i)->scn=(corp+sizec)->scn;
			strcpy((merged+i)->name,(corp+sizec)->name);
			strcpy((merged+i)->surname,(corp+sizec)->surname);			
			sizec++;
		}
		else if(((corp+sizec)->scn)<((tech+sizet)->scn))
		{
			(merged+i)->scn=(corp+sizec)->scn;
			strcpy((merged+i)->name,(corp+sizec)->name);
			strcpy((merged+i)->surname,(corp+sizec)->surname);			
			sizec++;
		}
		else if(((tech+sizet)->scn)<((corp+sizec)->scn))
		{
			(merged+i)->scn=(tech+sizet)->scn;
			strcpy((merged+i)->name,(tech+sizet)->name);
			strcpy((merged+i)->surname,(tech+sizet)->surname);
			sizet++;
		}
	
	}
}
int main()
{
	phone_t corp[30];
	phone_t tech[30];
	phone_t merged[30];
	
	FILE *inp1;
	FILE *inp2;
	FILE *inp3;
	int sizeFile1;
	int sizeFile2;
	read(inp1,inp2,corp,tech,&sizeFile1,&sizeFile2);
//	printf("s%d\ns%d",sizeFile1,sizeFile2);	
	sort(corp,tech,sizeFile1,sizeFile2);
	
/*	for(int i=0;i<sizeFile1;i++)
	{
		printf("%d ",(corp+i)->scn);
		printf("%s ",(corp+i)->name);
		printf("%s\n",(corp+i)->surname);
	}
	
	for(int i=0;i<sizeFile2;i++)
	{
		printf("%d ",(tech+i)->scn);
		printf("%s ",(tech+i)->name);
		printf("%s\n",(tech+i)->surname);
	}*/
	inp3=fopen("clients.txt","w");
//	printf("%d ",(merged+0)->scn);
	merge(merged,corp,tech,sizeFile1,sizeFile2);
	int tplm=sizeFile1+sizeFile2;
	printf("\n%d\n\n",tplm);
	for(int i=0;i<25;i++)
	{
		printf("%d ",(merged+i)->scn);
		printf("%s ",(merged+i)->name);
		printf("%s\n",(merged+i)->surname);
	}
//	fprintf(inp3,"kadir");
	for(int i=0;i<tplm;i++)
	{
		fprintf(inp3,"%d ",(merged+i)->scn);
		fprintf(inp3,"%s ",(merged+i)->name);
		fprintf(inp3,"%s\n",(merged+i)->surname);
	}	
	
	
	
}
