#include<stdio.h>
#include<string.h>

typedef struct{
char name[30];
int age;
double gpa;
}stu_t;
int menu(int *x)
{
	
	printf("1) Go to record X from top\n");
	printf("2) Move X record ahead\n");
	printf("3 Go  Xrecord from bottom\n");
	printf("4) Exit\n");
	
	int select;

	printf("Enter your choice: ");
	scanf("%d",&select);
	if(select!=4)
	{
		printf("Enter X: ");
		scanf("%d",x);
	}
	

	
	return select;
}

int main()
{
	FILE *f1=fopen("info.txt","r");
	FILE *f2=fopen("binary.bin","wb");
	FILE *f3=fopen("binary.bin","rb");
	
	stu_t info[15];
	stu_t temp;
	
	for(int i=0;i<15;i++)
	{
		fscanf(f1,"%s %d %lf",(info+i)->name,&(info+i)->age,&(info+i)->gpa);
	}
	
	for(int i=0;i<15;i++)
		{
//			printf("%s\t%d\t%3.2f\n",(info+i)->name,(info+i)->age,(info+i)->gpa);
		fwrite(&(info[i]),sizeof(stu_t),1,f2);
		}
	
	
	int x;
	fclose(f2);
	fclose(f1);
	int select=menu(&x);
//	printf("%d\n%d\n",select,x);
//	printf("%d",select);
	while(select!=4)
	{
		if(select==1)
		{
			fseek(f3,sizeof(stu_t)*(x-1),SEEK_SET);
		//	fseek(f3, (x) * sizeof(int),SEEK_SET);
			fread(&temp,sizeof(stu_t),1,f3);
			printf("%s\t%d\t%3.2f\n",temp.name,temp.age,temp.gpa);
			
		}
		else if(select==2)
		{
			fseek(f3,sizeof(stu_t)*(x-1),SEEK_CUR);
			fread(&temp,sizeof(stu_t),1,f3);
			printf("%s\t%d\t%3.2f\n",temp.name,temp.age,temp.gpa);
			
		}
		else if(select==3)
		{
			fseek(f3,sizeof(stu_t)*(-x),SEEK_END);
			fread(&temp,sizeof(stu_t),1,f3);
			printf("%s\t%d\t%3.2f\n",temp.name,temp.age,temp.gpa);
			
		}
			select=menu(&x);
//			printf("%d\n%d\n",select,x);
	}
	fclose(f3);
}
