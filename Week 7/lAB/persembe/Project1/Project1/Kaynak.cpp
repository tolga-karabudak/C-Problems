#include<stdio.h>
#include<string.h>


typedef struct emp
{
	int id;
	char name[20];
	char surname[20];
};

int main()
{
	emp info[100];

	FILE *inp = fopen("Employee.txt", "r");
	int i = 0;
	while (fscanf(inp, "%d", &(info + i)->id) != EOF)
	{
		fscanf(inp, "%s %s", (info + i)->name, (info + i)->surname);
		i++;
	}



	return 0;
}