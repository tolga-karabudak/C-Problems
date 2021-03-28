#include<stdio.h>
#include<string.h>



typedef struct{
	char name[15];
	char where[15];
	int pop;
	
}city;

int readAndWrite(FILE *inp,FILE *inp2,city*info)
{
	int size=0;
	while(fscanf(inp,"%s%s%d",(info+size)->name,(info+size)->where,&(info+size)->pop)!=EOF)
		size++;	
	return size;
}

int recursiveBinarySearch(city *info,int top, int bottom, char search[15])
{
	int mid=(top+bottom)/2;
	if(top>bottom)
		return -1;
	else if(strcmp(search,(info+mid)->name)==0)
		return mid;
	else if(strcmp(search,(info+mid)->name)>0)
		top=mid+1;
	else if(strcmp(search,(info+mid)->name)<0)
		bottom=mid-1;
	recursiveBinarySearch(info,top,bottom,search);
		
}
int main()
{
	city info[50];
	FILE *inp,*inp2;
	inp=fopen("cities.txt","r");
	inp2=fopen("cities.bin","wb");;
	
	int size=readAndWrite(inp,inp2,info);
	for (int i=0;i<42;i++)
		printf("%s  %s  %d\n",(info+i)->name,(info+i)->where,(info+i)->pop);
	printf("Enter a city name:");
	char search[15];
	scanf("%s",search);
	int result=recursiveBinarySearch(info,0,size-1,search);
	
	if(result==-1)
		printf("'%s' could not be found!!!",search);
	else 
		printf("%s\t%s\t%d",(info+result)->name,(info+result)->where,(info+result)->pop);
	

}
