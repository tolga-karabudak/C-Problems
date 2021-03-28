/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to replace a string with "*"

void rep_str(char *s, char *key)
{

	int i;
	int keylen = strlen(key);
	int sentlen = strlen(s);
	//char result[50] = ""; //for the alternative solution
	//char star[] = "*";


	for (i = 0; i < sentlen - keylen; i++)
	{
		if ((strncmp(s + i, key, keylen) == 0 && (i == 0 || *(s + i + keylen) == ' ' || *(s + i - 1) == ' ' || *(s + i + keylen) == '\0')))
			//compare the substring with the newstring and check if the substring is at the right position of a word
		{
			*(s + i) = '*';
			strcpy(s + i + 1, s + i + keylen);
		}

	}

	/*while (*s != '\0')
	{
		if ((strncmp(s, key, keylen) == 0 && (i == 0 || *(s + keylen) == ' ' || *(s - 1) == ' ' || *(s + keylen) == '\0')))
			//compare the substring with the newstring and check if the substring is at the right position of a word
		{
			strcpy(result + i, star);
			i += newlen; //adding newlength to the new string
			s += keylen;//adding the same old length the old string
		}
		else
			result[i++] = *s++;
	}
	strcpy(s, result);*/
	

}

int main(void)
{
	char mystr[100], control[10];
	printf("Enter a Text:\n");
	scanf("%[^\n]s", mystr);
	printf("Enter a String:\n");
	scanf(" %s", control);

	printf("Old Text: %s\n", mystr);
	rep_str(mystr, control);
	printf("New Text: %s\n", mystr);

	return 0;
}