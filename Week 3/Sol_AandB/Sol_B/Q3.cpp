#include <stdio.h>
#include <string.h>
//CENG104 Author: Evren
#define DEPT 3
#define EMP 10
#define HRS 40
#define PER 2.0
#define OVER 5.0

typedef struct
{
	int id;
	char name[15];
	int age;
	int worked_hr;
	double salary;
} workers_t;

typedef struct
{
	int d_id;
	char d_name[30];
	workers_t worker[10];
}depart_t;

void readFile(depart_t *dep, FILE *inp);

void totalSalary(depart_t *dep);

void display(depart_t *dep);

int main(void)
{
	FILE *inp;
	depart_t dep[3];
	inp = fopen("employee.txt", "r");
	if (inp == NULL)
		printf("File can not be opened");
	else
	{
		readFile(dep, inp);
		totalSalary(dep);
		display(dep);
	}

	return 0;
}

void readFile(depart_t *dep, FILE *inp)
{
	int j, i;
	for (i = 0; i < DEPT; i++)
	{
		fscanf(inp, "%d", &(dep + i)->d_id);
		fscanf(inp, "%[^\n]s", (dep + i)->d_name);
		for (j = 0; j < EMP; j++)
			fscanf(inp, "%d %s %d %d", &(dep + i)->worker[j].id, (dep + i)->worker[j].name, &(dep + i)->worker[j].age, &(dep + i)->worker[j].worked_hr);
	}
}

void totalSalary(depart_t *dep)
{
	int i, j;
	for (j = 0; j < DEPT; j++)
	{
		for (i = 0; i < EMP; i++)
		{
			if (dep[j].worker[i].worked_hr <= HRS)
				dep[j].worker[i].salary = dep[j].worker[i].worked_hr * PER;
			else
				dep[j].worker[i].salary = HRS * PER + (dep[j].worker[i].worked_hr - HRS) * OVER;
		}
	}
}

void display(depart_t *dep)
{
	for (int j = 0; j < DEPT; j++)
	{
		printf("      %s DEPARTMENT\n\n", (dep + j)->d_name);

		printf("ID     NAME      AGE   HOURS WORKED    SALARY\n");
		printf("*** ***********  ***   ************   ********\n");

		for (int i = 0; i < 10; i++)
			printf("%3d %-11s %5d %7d %15.2fTL\n", (dep + j)->worker[i].id, (dep + j)->worker[i].name, (dep + j)->worker[i].age, (dep + j)->worker[i].worked_hr, (dep + j)->worker[i].salary);

		printf("\n");
	}
}