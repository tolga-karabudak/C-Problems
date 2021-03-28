#include <stdio.h>
#include <string.h>
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
#define SIZE 150
#define SIZE2 20

int findLastOcc(char sent[], char srch[])
{
	int i,
		lensent = strlen(sent),
		lensrch = strlen(srch);


	for (i = lensent - lensrch; i >= 0; i--)
		if (strncmp(sent + i, srch, lensrch) == 0)
			return i;
	return -1;
}

int main()
{
	char sent[SIZE], keystr[SIZE2];

	int indx;

	printf("Enter a sentence: ");
	scanf(" %[^\n]s", sent);
	printf("Enter a key string: ");
	scanf(" %s", keystr);

	indx = findLastOcc(sent, keystr);
	if (indx != -1)
	{
		if (indx == 0)
		{
			printf("That's an empty string, sorry..\n");
		}
		else
		{
			strncpy(sent, sent, indx);
			sent[indx] = '\0';

			printf("Result: %s\n", sent);
		}
	}
	else
		printf("Result: %s\n", sent);

	return 0;
}