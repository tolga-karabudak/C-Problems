#include<stdio.h>
#include<string.h>

typedef struct{
	char service[40];
	char date[15];
	char comp[40];
	
}info;

int binarySearch(FILE*inp,int top,int bottom,char find[40])
{
	int mid;
	char temp[40];
	int size=strlen(find);

	while(top<=bottom)
	{
		mid=(top+bottom)/2;	
		fseek(inp,(mid)*sizeof(info),SEEK_SET);
		fread(temp,sizeof(temp),1,inp);
	//	printf("%s",temp);
		if(strncmp(find,temp,size)==0)
			return mid;
		else if(strncmp(find,temp,size)>0)
			top=mid+1;
		else if(strncmp(find,temp,size)<0)
			bottom=mid-1;
		mid=(top+bottom)/2;			
	}
	 return -1;
}

int main()
{
	FILE *inp=fopen("renewals.bin","rb");
	info temp;
	int size=0;
	
	while(!feof(inp))
	{
		fread(&temp,sizeof(temp),1,inp);
		printf("%s   %s   %s\n",temp.service,temp.date,temp.comp);
		size++;
	}
	size=size-1;
	printf("%d\n\n",size);
	printf("Enter a service to search : ");
	char tmp[40];
	gets(tmp);
	
	int index=binarySearch(inp,0,size-1,tmp);
	if(index==-1)
		printf("There is no such renewal service!!");
	else
	{
		fseek(inp,index*sizeof(info),SEEK_SET);
		fread(&temp,sizeof(temp),1,inp);	
		printf("Service: %s\nDate: %s\nTo be paid to: %s\n",temp.service,temp.date,temp.comp);
	}
	
	
	
}
