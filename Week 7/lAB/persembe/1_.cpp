#include<stdio.h>
#include<string.h>

typedef struct emp
{
	int id;
	int salary;
	char name[20];
	char surname[20];
};
void swap(emp *info,int i,int j)
{
	int temp=(info+i)->id;
	(info+i)->id=(info+j)->id;
	(info+j)->id=temp;
	temp=(info+i)->salary;
	(info+i)->salary=(info+j)->salary;
	(info+j)->salary=temp;
	char tmp[30];
	strcpy(tmp,(info+i)->name);
	strcpy((info+i)->name,(info+j)->name);
	strcpy((info+j)->name,tmp);
	strcpy(tmp,(info+i)->surname);
	strcpy((info+i)->surname,(info+j)->surname);
	strcpy((info+j)->surname,tmp);	
}

void rec_bubble_sort(emp *info,int i)
{
	if(i==1)
		return ;
	for(int k=0;k<i-1;k++)
	{
		if((info+k)->id>(info+k+1)->id)
			swap(info,k,k+1);
	}
	rec_bubble_sort(info,i-1);
}

int rec_binary_search(emp *info, int top, int bottom,int select)
{
	if(top>bottom)
		return -1;
	int middle=(top+bottom)/2;
	if((info+middle)->id==select)
		return middle;
	else if((info+middle)->id<select)
		top=middle+1;
	else if((info+middle)->id>select)
		bottom=middle-1;
	rec_binary_search(info,top,bottom,select);
}

int main()
{
	char fname[30];
	printf("Enter a file name: ");
	gets(fname);
	
	while(strcmp(fname,"Employee.txt")!=0)
	{
		printf("File not found Enter again ");
		gets(fname);
	}
	emp *info;
	FILE *inp = fopen("Employee.txt", "r");
	int size = 0;
	while (fscanf(inp, "%d", &(info + size)->id) != EOF)
	{	fscanf(inp, "%s %s", (info + size)->name, (info + size)->surname);
		fscanf(inp, "%d", &(info + size)->salary);
		size++;
	}			
//	for(int j=0;j<size;j++)
//		printf("%d\t%s\t%s\t%d\n",(info+j)->id,(info+j)->name,(info+j)->surname,(info+j)->salary);
	printf("%d",size);
	rec_bubble_sort(info,size);
	
	printf("-------\n");
	for(int j=0;j<size;j++)
		printf("%d\t%s\t%s\t%d\n",(info+j)->id,(info+j)->name,(info+j)->surname,(info+j)->salary);
	printf("Enter an employee id (-1 to stop): ");
	int select;
	scanf("%d",&select);
	while(select!=-1)
	{
		int find=find=rec_binary_search(info,0,size-1,select);
		if(find==-1)
			printf("ID not found!!!") ;
		else
			printf("%d %s\t%s\t%d\n",(info+find)->id,(info+find)->name,(info+find)->surname,(info+find)->salary);
		printf("Enter an employee id (-1 to stop): ");
		scanf("%d",&select);
	}

	return 0;
}
