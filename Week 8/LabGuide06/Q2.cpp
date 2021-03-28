// Author: Evren
#include<stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "stack_char.h"

int palindrome(char *sent)
{
	int i, len = strlen(sent);
	char value;

	stack_t st;
	initialize_s(&st);

	for (i = 0; i<len / 2; i++)
		push(&st, sent[i]);

	if (len % 2 == 1)
		i++;

	//pop a value from the stack which is the last character of the sentence
	value = pop(&st);


	//check if the popped value is equal to the current character
	while (i <= len && value == sent[i])
	{
		if (!is_empty_s(&st))						//till the stack is empty, continue popping values
			value = pop(&st);
		i++;
	}

	//if i is equal to length of the sentence,
	//that means the outer while above is processed till i reaches the length of sentence,
	//so we can say the sentence is palindrome
	if (i == len)
		return 1;
	else
		return 0;
}

int main(void)
{
	char sent[100];
	int status;

	FILE *inp = fopen("palindrome.txt", "r");

	if (inp == NULL)
		printf("\nFile cannot be opened!\n");
	else
	{
		status = fscanf(inp, " %[^\n]s", sent);
		while (status != EOF)
		{
			if (palindrome(sent))
				printf("%s\n", sent);

			status = fscanf(inp, " %[^\n]s", sent);
		}
	}
	printf("\n\n");
	return(0);
}
