#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char name[20] ;
	char surname[20];
	char id[20];
	char age[20];
	char salary[20] ;
	char dep[20] ;
}emp_t;

void parser(emp_t *emp,char str[100])
{	
	int size=strlen(str);
	int flag=0;
	for(int i=0;i<size+1;i++)
	{
		char temp[20]={"                   "};
		int size1=0;
		int des=i;
		while(*(str+i)!=':'&&i<size)
			{
					size1++;
					i++;					
			}
			strncpy(temp,str+des,size1);
		//	printf("%d\n",c);
		//	printf("%s\n",temp);
		
			if(flag==0)
				strcpy(emp->name,temp);
			else if(flag==1)
				strcpy(emp->surname,temp);
			else if(flag==2)
				strcpy(emp->id,temp);
			else if(flag==3)
				strcpy(emp->age,temp);
			else if(flag==4)
				strcpy(emp->salary,temp);
			else if(flag==5)
				strcpy(emp->dep,temp);			
			flag++;
	}
//	printf("%s",emp.name);
}


int main()
{	
	emp_t emp;
	char str[100];
	printf("Enter an employee:");
	gets(str);
	printf("Enter increase in the salary: ");
	int a;
	scanf("%d",&a);
//	printf("%s\n",str);	
	
	parser(&emp,str);
	printf("Name: %s\n",emp.name);
	printf("Surname: %s\n",emp.surname);	
	printf("Employee ID: %s\n",emp.id);
	printf("Age: %s\n",emp.age);
	int s=atoi(emp.salary);
	s=s+a;
//	printf("%s\n",emp.salary);
	printf("Salary: %d\n",s);
	printf("Deparment: %s\n",emp.dep);


	
}
