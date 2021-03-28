#include<stdio.h>
#include<string.h>

int main()
{
	FILE *binaryp;
	FILE *out=fopen("nums.bin","rb");
	int i;
	binaryp = fopen("nums.bin", "wb");
	
	for (i = 5; i <= 2000; i += 5)
	{
		fwrite(&i, sizeof(int), 1, binaryp);
	//	printf("%d\n",i);
	}
	fclose(binaryp);
	int x;
	printf("How many numbers do you want to read: ");
	scanf("%d",&x);
	while(x<1||x>500)
	{
		printf("Enter a number between 1 and 500! ");
		scanf("%d",&x);
	}
	int arr[500];
//	rewind(binaryp);
		for(int i=0;i<x;i++)
			fread((arr+i),sizeof (int),1,out);
//	printf("%d",arr[3]);
	
	for(int i=0;i<x;i++)
		printf("%d\n",*(arr+i));
	
		
	
	
	
	
}
