#include <stdio.h>
#include <string.h>
#define SIZE 20
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
int
longest(char words[][SIZE], int n)
{
	int i,
		maxInd = n-1,
		maxLen = strlen(words[n-1]),
		len;

	for (i = n-2; i >=0; i--)
	{
		len = strlen(words[i]);

		if (len > maxLen)
		{
			maxInd = i;
			maxLen = len;
		}
	}
	return maxInd;
}

int
main(void)
{
	char words[SIZE][SIZE];
	char temp[SIZE];
	int i, maxInd;
	
	i = 0;
	printf("Enter a word (or STOP): ");
	scanf("%s", temp); 
	
	while (strcmp(temp, "STOP") != 0)
	{
		strcpy(words[i], temp);
		i++;

		printf("Enter a word (or STOP): ");
		scanf("%s", temp);
	}
	
	maxInd = longest(words, i);

	printf("\nLongest word:%s\nLength: %d\n\n", words[maxInd], strlen(words[maxInd]));

	return (0);
}


