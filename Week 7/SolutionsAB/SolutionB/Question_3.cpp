#include<stdio.h>
/* CENG104 LG5 
Author: Evren*/
typedef struct
{
	char name[20];
	int age;
	double gpa;
}stu_t;

int menu()
{
	int choice;

	printf("\n1) Go to record X from top");
	printf("\n2) Move X records ahead");
	printf("\n3) Go X records back from bottom");
	printf("\n4) Exit");

	printf("\n\nEnter your choice: ");
	scanf("%d", &choice);

	return (choice);
}

int main()
{
	stu_t list[20];
	stu_t record;
	int i = 0, choice, exit = false, X;

	FILE *inp = fopen("info.txt", "r");
	if (inp == NULL)
		printf("Error : info.txt not found!\n");
	else
	{
		FILE *b_outp = fopen("binary", "wb");
		while (fscanf(inp, "%s %d %lf", list[i].name, &list[i].age, &list[i].gpa) != EOF)
			i++;

		fwrite(list, sizeof(stu_t), i, b_outp);
		fclose(b_outp);

		b_outp = fopen("binary", "rb");
		do {
			choice = menu();
			switch (choice)
			{
			case 1:
				printf("\nEnter X: ");
				scanf("%d", &X);
				fseek(b_outp, sizeof(stu_t)*(X - 1), SEEK_SET);
				fread(&record, sizeof(stu_t), 1, b_outp);
				printf("\n%-6s %d %5.2f\n", record.name, record.age, record.gpa);
				break;
			case 2:
				printf("\nEnter X: ");
				scanf("%d", &X);
				fseek(b_outp, sizeof(stu_t)*(X - 1), SEEK_CUR);
				fread(&record, sizeof(stu_t), 1, b_outp);
				printf("\n%-6s %d %5.2f\n", record.name, record.age, record.gpa);
				break;
			case 3:
				printf("\nEnter X: ");
				scanf("%d", &X);
				fseek(b_outp, sizeof(stu_t)*-X, SEEK_END);
				fread(&record, sizeof(stu_t), 1, b_outp);
				printf("\n%-6s %d %5.2f\n", record.name, record.age, record.gpa);
				break;
			case 4:
				exit = true;
				break;
			default:
				printf("\nInvalid choice!");
			}
		} while (!exit);
	}
	return 0;
}

