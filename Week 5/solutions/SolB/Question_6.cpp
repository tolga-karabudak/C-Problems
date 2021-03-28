#include<stdio.h>
#include <string.h>
#define MAX_COL 20
#define MAX_ROW 100
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
//read bike names from the file into the structure array
int
readBikeList(FILE *inp, char bike[][MAX_COL])
{
	int i = 0, status;

	status = fscanf(inp, "%s", bike[i]);
	while (status != EOF)
	{
		i++;
		status = fscanf(inp, " %s", bike[i]);
	}
	return i;
}

//move all of the elements in the following positions of A one element down 
//to make room for the element coming from B
void shiftDown(char ar[][MAX_COL], int size, int pos)
{
	int k;
	for (k = size - 1; k >= pos; k--)
		strcpy(ar[k + 1], ar[k]);
}

//merges the elements of two sorted arrays and uses one of those arrays to
//store the merged values.
void merge(char A[][MAX_COL], int sizeA, char B[][MAX_COL], int sizeB)
{
	int kA = 0, kB = 0;

	while (kA < sizeA && kB < sizeB)
	{
		if (strcmp(B[kB], A[kA]) <= 0)
		{
			shiftDown(A, sizeA, kA);
			strcpy(A[kA], B[kB++]);
			sizeA++;
		}
		kA++;
	}

	/* if the end of A is reached, copy the remaining
	elements of B to the end of A */
	if (kA == sizeA)
		while (kB < sizeB)
		{
			strcpy(A[kA++], B[kB++]);
			sizeA++;
		}
}
//write the merged list to the file bike_list.txt 
void
writeToFile(char bike[][MAX_COL], int size)
{
	int j;
	FILE *outp;

	outp = fopen("bike_list.txt", "w");
	for (j = 0; j < size; j++)
		fprintf(outp, "%s\n", bike[j]);

	fclose(outp);
}

int main(void)
{
	FILE *inp1, *inp2;
	char bike1[MAX_ROW][MAX_COL], bike2[MAX_ROW][MAX_COL];
	int size1 = 0, size2 = 0, status, j;

	inp1 = fopen("bike1.txt", "r");
	inp2 = fopen("bike2.txt", "r");

	if (inp1 == NULL || inp2 == NULL)
		printf("One of the files can not be opened!");
	else
	{		
		size1 = readBikeList(inp1, bike1);
		size2 = readBikeList(inp2, bike2);

		fclose(inp1);
		fclose(inp2);

		merge(bike1, size1, bike2, size2);

		writeToFile(bike1, size1 + size2);
	}

	return(0);
}

