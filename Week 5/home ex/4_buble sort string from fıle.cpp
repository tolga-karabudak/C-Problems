#include<string.h>
#include<stdio.h>
void buble_sort_string(char arr[6][15],int size){	
	for(int pass=1;pass<size-1;pass++){
		for(int k=0;k<size-pass;k++){
			if(strcasecmp(arr[k],arr[k+1])>0){
				char temp[15];
				strcpy(temp,arr[k]);
				strcpy(arr[k],arr[k+1]);
				strcpy(arr[k+1],temp);	
			}
			
		}
	}
}
			


int main()
{
	char arr[6][15];
	FILE *inp=fopen("words.txt","r");
	int i=0;
	while(fscanf(inp,"%s",(arr+i))!=EOF)
	{
		i++;
	}
	int pass=1;
	int size=i;
	for(int a=0;a<size;a++)
		printf("%s\n",arr[a]);
	printf("********\n");
	buble_sort_string(arr,size);
	for(int a=0;a<size;a++)
		printf("%s\n",arr[a]);
//	printf("\n%d",pass);
	
}
