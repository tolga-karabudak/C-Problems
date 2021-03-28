//CENG104 LG02/B - Author: Evren
#include <stdio.h>
#define SIZE 10 
typedef struct
{
	int model, price;
	char type[10];
}car_t;

int menu()
{
	int choice;

	printf("\nAccording to:\n");
	printf("1.Type\n");
	printf("2.Model\n");
	printf("3.Price range\n");
	printf("4.EXIT\n");

	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice>4);

	return choice;
}

int main()
{
	FILE *inp = fopen("cars.txt", "r");

	if (inp == NULL)
		printf("\nError while opening the input file\n");
	else
	{
		int choice, size = 0, k, status;

		car_t cars[SIZE];

		char ctype;
		int cmodel, pr1, pr2;

		while (fscanf(inp, "%s %d %d", (cars + size)->type, &(cars + size)->model, &(cars + size)->price) != EOF)
		{
			size++;
		}

		choice = menu();
		while (choice != 4)
		{
			switch (choice)
			{
			case 1:	
				do{
					printf("\nEnter a type (P:Peugeot, M:Mercedes, H:Honda): ");
					scanf(" %c", &ctype);
				} while (ctype != 'P' && ctype != 'M' && ctype != 'H');

				for (int k = 0; k < size; k++)
					//if (*((cars + k)->type) == ctype)
					if ((cars + k)->type[0] == ctype)
						printf("%-15s %d %d\n", (cars + k)->type, (cars + k)->model, (cars + k)->price);
				break;

			case 2: printf("\nEnter a model year: ");
					scanf("%d", &cmodel);

					for (k = 0; k < size; k++)
						if ((cars + k)->model == cmodel)
							printf("%-15s %d %d\n", (cars + k)->type, (cars + k)->model, (cars + k)->price);
				break;
			case 3: 
				do{
					printf("\nEnter a price range: ");
					scanf("%d %d", &pr1, &pr2);
				} while (pr1 > pr2);

				for (k = 0; k < size; k++)
					if ((*(cars + k)).price >= pr1 && (*(cars + k)).price <= pr2)
						printf("%-15s %d %d\n", (cars + k)->type, (cars + k)->model, (cars + k)->price);
				break;
			}
			choice = menu();
		}
		fclose(inp);
	}
	return 0;
}