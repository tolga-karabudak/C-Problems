#include<stdio.h>
#include<string.h>
#define SIZE1 100
#define SIZE2 20
#define SIZE3 10
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
//person information
typedef struct
{
	char name[SIZE2];
	char sname[SIZE2];
	char plate[SIZE3];
}person_t;

//search list for a plate using Sequential search algorithm
int binarySearch(person_t data[], int top, int bottom, char srchPlate[], int *comp)
{
	int middle;

	while (top <= bottom)
	{
		middle = (top + bottom) / 2;
		(*comp)++;

		if (strcmp(data[middle].plate, srchPlate) == 0)
			return middle;
		else
			if (strcmp(data[middle].plate, srchPlate) > 0)
				bottom = middle - 1;
			else
				top = middle + 1;
	}
	return(-1);
}
int main()
{
	person_t data[SIZE1];
	int i = 0, comp, status, indx;
	char srchPlate[SIZE2];

	FILE *inp = fopen("plates.txt", "r");

	//read person information from file into the structure array
	status = fscanf(inp, "%s", data[i].name);
	while (status != EOF)
	{
		fscanf(inp, "%s", data[i].sname);
		fscanf(inp, "%s\n", data[i].plate);
		i++;

		status = fscanf(inp, "%s", data[i].name);
	}

	//read a plate to search until "END" is given
	printf("Enter plate of a car (END for exit): ");
	scanf("%s", srchPlate);

	while (strcmp(srchPlate, "END") != 0)
	{
		comp = 0;
		indx = binarySearch(data, 0, i-1, srchPlate, &comp);
		if (indx != -1)
			printf("%s %s %s\n", data[indx].name, data[indx].sname, data[indx].plate);
		else
			printf("NOT FOUND\n");

		printf("%d comparisons.\n\n", comp);

		printf("Enter plate of a car (END for exit): ");
		scanf("%s", srchPlate);
	}

	return 0;
}
