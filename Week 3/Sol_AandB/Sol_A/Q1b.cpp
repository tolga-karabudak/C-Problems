# include <stdio.h>
#define SIZE 30

int myStrLen(char *str);

int main()
{

	FILE *inp, *outp;

	char name[SIZE];
	int len;

	inp = fopen("words.txt", "r");

	if (inp == NULL)
		printf("\n File can NOT be found\n");
	else
	{
		outp = fopen("result.txt", "w");

		while (fscanf(inp, "%s", name) != EOF)
		{
			len = myStrLen(name);
			fprintf(outp, "%s - %d\n", name, len);
		}

		fclose(inp);
		fclose(outp);
	}

	return 0;
}

int myStrLen(char *str)
{
	int	i = 0;

	while (*(str + i) != '\0')
		i++;

	return i;
}