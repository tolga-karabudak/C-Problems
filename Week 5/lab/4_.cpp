
#include<string.h>
#include<stdio.h>
void buble_sort_string(char arr[10][15],int size){	
	for(int pass=1;pass<size-1;pass++){
		for(int k=0;k<size-pass;k++){
			if(strcmp(arr[k],arr[k+1])>0){
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
	char arr[10][15];
	
	char end[]={"end"};
	int i=0;
	printf("Ener a song name (end to stop): ");
	gets(arr[i]);
//	printf("%s",arr[i]);
	
	while(strcmp(arr[i],end)!=0)
	{
		i++;
	//	printf("13123123");
	printf("Ener a song name (end to stop): ");
		gets(arr[i]);
	}
	
//	printf("%s",arr[0]);
//	printf("%s",arr[1]);
//	printf("%s",arr[2]);

	printf("Disco Songs\n");
	printf("-----------\n");

	int size=i;
	buble_sort_string(arr,size);
	for(int a=0;a<size;a++)
		printf("%d) %s\n",a+1,arr[a]);
//	printf("\n%d",pass);
	
}
