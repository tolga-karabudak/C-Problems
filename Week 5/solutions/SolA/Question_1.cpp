#include <stdio.h>
#include <string.h>
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
#define SIZE 20
#define AREA "(312) "
#define WITHAREA 10
#define WITHOUTAREA 7
#define AREASIZE 3
#define PHONE 7

int
readFromFile(FILE *inp, char phones[][SIZE])
{
	int	i, status;
	i = 0;
	status = fscanf(inp, "%s", phones[i]);
	while (status != EOF)
	{
		i++;
		status = fscanf(inp, "%s", phones[i]);
	}
	return i;
}

void
updateDirectory(char phones[][SIZE], int n)
{
	char temp[SIZE];
	int i, len;
	
	for (i = 0; i < n; i++)
	{
		strcpy(temp, "");

		len = strlen(phones[i]);
		if (len == WITHOUTAREA)
		{
			strcat(temp, AREA);
			strcat(temp, phones[i]);
			strcpy(phones[i], temp);
		}
		else
		{
			strcat(temp, "(");
			strncat(temp, phones[i], AREASIZE);
			strcat(temp, ") ");
			strncat(temp, phones[i] + AREASIZE, PHONE);
			strcpy(phones[i], temp);
		}
	}
}
void
printDirectory(char phones[][SIZE], int n)
{
	int i;
	printf("There are %d phone numbers in the directory\n", n);
	for (i = 0; i < n; i++)
		printf("%s\n", phones[i]);
}
int
main(void)
{
	FILE * inp;
	char phones[SIZE][SIZE];
	int noOfPhones;

	inp = fopen("phones.txt", "r");

	if (inp == NULL)
		printf("Error!\n");
	else
	{
		noOfPhones = readFromFile(inp, phones);

		updateDirectory(phones, noOfPhones);
		printDirectory(phones, noOfPhones);

		fclose(inp);
	}

	return(0);
}


/* phones.txt
3124250204
2660408
3122748540
3123659874
3123547862
2660808
2905128
3124421578*/

/*
There are 8 phone numbers in the directory
(312) 4250204
(312) 2660408
(312) 2748540
(312) 3659874
(312) 3547862
(312) 2660808
(312) 2905128
(312) 4421578
*/