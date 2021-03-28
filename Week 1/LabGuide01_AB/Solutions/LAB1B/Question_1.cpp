#define _CRT_SECURE_NO_WARNINGS
/*CENG104 Lab1-B Question1
Author: Evren*/
#include <stdio.h>
#define CITYCOUNT 4
#define YEARS 5
void readFile(FILE *p, int ar1[], int ar2[][YEARS]) 
{
	/*Read a file, which is referenced by p, 
	to separate the cities and the year values 
	to store them into two arrays until reaching end file*/
	int status; //to store the return integer value of a fscanf. remember: fscanf (scanf) always returns an integer value.

	for (int i = 0; i < CITYCOUNT; i++)
	{
		status = fscanf(p, "%d", &ar1[i]);//read and store cities
		for (int j = 0; j < YEARS && status != EOF; j++)
		{
			status = fscanf(p, "%d", &ar2[i][j]);//read and store degrees
		}
	}
}

void findHighestDegree(int ar[][YEARS], int *r, int *c) //to find the highest value in an 2D array
{/* 
	pointer r is for its row, 
	pointer c is for the column number*/
	//assume the first - the highest
	*r = 0;
	*c = 0;
	for (int i = 0; i < CITYCOUNT; i++)
	{
		for (int j = 0; j < YEARS; j++)
		{
			if (ar[*r][*c] < ar[i][j])//classic finding the max process
			{ 
				*r = i; //capture row and colums of the highest
				*c = j; //capture row and colums of the highest
			}
		}
	}
}

void findTotals(int arr[][YEARS], int arr2[])/*to find totals of each row of a 2D array 
											 and store it in a 1D array*/
{
	for (int i = 0; i < CITYCOUNT; i++)
	{
		arr2[i] = 0; //in each loop pass to next subscript and assign it to zero due to the below calculation (arr2[i] += arr[i][j])
		for (int j = 0; j < YEARS; j++)
		{
			arr2[i] += arr[i][j];
		}
	}
}

void printToFile(FILE *p, int ar1[], int ar2[]) /*according to the given question, 
												output must be written to a file with a given format*/
{
	for (int j = 0; j < CITYCOUNT; j++)
	{
		fprintf(p,"\n%02d\t\t%d",ar1[j],ar2[j]);
	}
}

int main()
{
	FILE *inp, *out;
	inp = fopen("input.txt","r"); //input.txt file is in memory with read mode only
	out = fopen("output.txt","w"); //output.txt file is in memory with write mode only
	if(inp!=NULL)
	{ 
		int city[CITYCOUNT], totals[CITYCOUNT], degrees[CITYCOUNT][YEARS]; //declaring arrays
		int row, column; //declaring variables
		readFile(inp, city, degrees); //calling the functions where needed
		findHighestDegree(degrees, &row, &column);
		findTotals(degrees, totals);
		//after completion of the calculations and findings, write them into a file
		fprintf(out,"Average highest degree is: %d\nYear: %d\nCity: %02d\n\n",degrees[row][column],(2012+column),city[row]);
		fprintf(out, "City\tTotal");
		printToFile(out,city,totals);
	}
	return 0;
}